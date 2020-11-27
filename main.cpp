#include <iostream>
#include <math.h>
#include "Signal.h"
#include "utils.h"

using namespace std;

int main() {
	/**
	 * Création du La 440
	 */
	int N = FREQ_ECHANTILLONAGE*6;
	Signal la440 = Signal(N);
	double note = 2.0 * M_PI * FREQ_A4 / (double) FREQ_ECHANTILLONAGE;
	for (int i = 0; i < N; ++i) {
		la440.signal[i] = sin((double) i * note);
	}
	la440.write_signal((char*) "../sons/la440.wav");

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
	 * Création du Do majeur
	 */
/*	Signal A4 = Signal();
	A4.read_signal("../sons/la440.wav");
	Signal C4 = Signal(A4);
	C4.incrementSemiTone(-9);
	Signal E4 = Signal(A4);
	E4.incrementSemiTone(-5);
	Signal G4 = Signal(A4);
	G4.incrementSemiTone(-2);
	Signal C4Majeur = Signal();
	return 0;*/
}
