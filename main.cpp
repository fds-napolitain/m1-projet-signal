#include <iostream>
#include <math.h>
#include "Signal.h"
#include "utils.h"
#include "Tone.h"

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
 * Test du filtre passe bas sur la flute
 */
void passeBas() {
	Signal signal = Signal((char*) "../sons/GammePiano.wav");
	signal.filter_low_pass(2000, 1);
	signal.write_signal((char*) "../sons/GammePianoBas.wav");
}

int main() {
//	la440();
//	verifDft();
	doMajeur();
//	passeBas();
	return 0;
}
