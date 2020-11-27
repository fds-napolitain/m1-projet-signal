#include <iostream>
#include <math.h>
#include "Signal.h"
#include "utils.h"

using namespace std;

int main() {
	/**
	 * Création du La 440
	 */
/*	Signal la440 = Signal(6.0);
	la440.addTone(FREQ_A4, 1.0, 1.0, 5.0);
	la440.write_signal((char*) "../sons/la440.wav");*/

	/**
	 * Vérification de DFT() et IDFT()
	 */
/*	cout << "Vérification que le signal est identique avant et après DFT/IDFT\n";
	Signal verif = Signal();
	verif.read_signal((char*) "../sons/la440.wav");
	for (int i = 0; i < sizeof(verif.signal); ++i) {
		printf("%f|", verif.signal[i]);
	}
	verif.dft();
	verif.idft();
	printf("\n");
	for (int i = 0; i < sizeof(verif.signal); ++i) {
		printf("%f|", verif.signal[i]);
	}*/

	/**
	 * TODO: Création du Do majeur
	 */
	Signal C4Majeur = Signal(3.0);
	double C4 = incrementSemiTone(FREQ_A4, -9);
	double E4 = incrementSemiTone(FREQ_A4, -5);
	double G4 = incrementSemiTone(FREQ_A4, -2);
	C4Majeur.addTone(C4, 1.0, 0, 3);
	C4Majeur.addTone(E4, 1.0, 0, 3);
	C4Majeur.addTone(G4, 1.0, 0, 3);
	C4Majeur.write_signal((char*) "../sons/doMajeur.wav");

	return 0;
}
