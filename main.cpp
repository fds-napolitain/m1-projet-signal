#include <iostream>
#include "Wave.h"
#include "Signal.h"

using namespace std;

int main() {
	/**
	 * Création d'un accord La majeur à partir du La440
	 */
	cout << "Création d'un accord La majeur à partir de A4\n";
	Signal signal1 = Signal();
	signal1.read_signal((char*) "../sons/GammePiano.wav");
	for (int i = 0; i < sizeof(signal1.signal); ++i) {
		printf("%f|", signal1.signal[i]);
	}
	signal1.dft();
	printf("\n");
	for (int i = 0; i < sizeof(signal1.a); ++i) {
		printf("%f|", signal1.a[i]);
	}
	signal1.idft();
	printf("\n");
	for (int i = 0; i < sizeof(signal1.signal); ++i) {
		printf("%f|", signal1.signal[i]);
	}
	return 0;
}
