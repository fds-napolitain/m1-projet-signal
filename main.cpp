#include <iostream>
#include <math.h>
#include "src/Signal.hpp"
#include "src/utils/utils.hpp"
#include "src/Tone.hpp"
#include "src/Effects.hpp"

using namespace std;

/**
 * Création du La 440
 */
void la440() {
	Tone A4 = Tone((char*) "A4");
	Signal la440 = Signal(6.0);
	la440.addTone(A4, 1.0, 5.0);
	la440.write_signal((char*) "../sons/la440.wav");
	Signal la442 = Signal(6.0);
}

/**
 * Vérification de DFT() et IDFT()
 */
void verifDft() {
	cout << "Vérification que le signal est identique avant et après DFT/IDFT\n";
	Signal verif = Signal((char*) "../sons/la440.wav");
	for (int i = 0; i < sizeof(verif.signal); ++i) {
		printf("%f|", verif.signal[i]);
	}
	verif.dft();
	verif.idft();
	printf("\n");
	for (int i = 0; i < sizeof(verif.signal); ++i) {
		printf("%f|", verif.signal[i]);
	}
}

void laChromatique() {
	Signal signal1 = Signal(4.0);
	Tone T_A4 = Tone((char*) "A4");
	signal1.addTone(T_A4, 0, 0.5);

}

/**
 * Création du Do majeur
 */
void doMajeur() {
	Signal C4 = Signal(3.0);
	Signal C4Majeur = Signal(3.0);
	Tone T_C4 = Tone((char*) "C4");
	Tone T_E4 = Tone((char*) "E4");
	Tone T_G4 = Tone((char*) "G4");
	Tones tones;
	tones.push_back(T_C4);
	tones.push_back(T_E4);
	tones.push_back(T_G4);
	C4.addTone(T_C4, 0, 3);
	C4Majeur.addTones(tones, 0, 3);
	C4.write_signal((char*) "../sons/do.wav");
	C4Majeur.write_signal((char*) "../sons/doMajeur.wav");
}

/**
 * Test du filtre passe bas sur la piano
 */
void fftFilters() {
	Signal passeBas = Signal((char*) "../sons/GammePiano.wav");
	passeBas.filter_low_pass2(1000);
	passeBas.write_signal((char*) "../sons/GammePianoBas.wav");
	Signal passeHaut = Signal((char*) "../sons/GammePiano.wav");
	passeHaut.filter_high_pass(1000, 1);
	passeHaut.write_signal((char*) "../sons/GammePianoHaut.wav");
	Signal passeHaut2 = Signal((char*) "../sons/la440.wav");
	passeHaut2.filter_high_pass(1000, 1);
	passeHaut2.write_signal((char*) "../sons/la440bas.wav");
	Signal passeBande = Signal((char*) "../sons/GammePiano.wav");
	passeBande.filter_pass_band(440, 1760, 1);
	passeBande.write_signal((char*) "../sons/GammePianoPasseBande.wav");
	Signal rejecteurBande = Signal((char*) "../sons/GammePiano.wav");
	rejecteurBande.filter_reject_band(440, 1760, 1);
	rejecteurBande.write_signal((char*) "../sons/GammePianoRejecteurBande.wav");
	Signal transpose = Signal((char*) "../sons/GammePiano.wav");
	transpose.transposition(-12);
	transpose.write_signal((char*) "../sons/GammePianoTranspose.wav");
}

void temporalFilters() {
	Signal signal = Signal((char*) "../sons/GammePiano.wav");
	signal.filter_butterworth(500);
	signal.write_signal((char*) "../sons/GammePianoBasButterworth.wav");
}

int main() {
	la440();
//	verifDft();
//	doMajeur();
	fftFilters();
	temporalFilters();
	return 0;
}
