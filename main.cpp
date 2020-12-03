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
	Tone A4 = Tone("A4");
	Signal la440 = Signal(6.0);
	la440.addTone(A4.freq, 1.0, 1.0, 5.0);
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
	Signal C4Majeur = Signal(3.0);
	Tone C4 = Tone("C4");
	Tone E4 = Tone("E4");
	Tone G4 = Tone("G4");
	C4Majeur.addTone(C4.freq, 0.33, 0, 3);
	C4Majeur.addTone(E4.freq, 0.33, 0, 3);
	C4Majeur.addTone(G4.freq, 0.33, 0, 3);
	C4Majeur.write_signal((char*) "../sons/doMajeur.wav");
}

int main() {
//	la440();
//	verifDft();
	doMajeur();
	return 0;
}
