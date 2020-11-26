#include <iostream>
#include <cmath>
#include "Wave.h"

using namespace std;

/*
 * Utils -----------------------------------------------------------
 */

/**
 * Signal en 8 bits (amplitude de 0 à 255 avec 127 pour 0)
 * @param signal
 * @return
 */
unsigned char doubleToUnsignedChar(double signal) {
	if (signal > 255) {
		return (unsigned char) 255;
	} else if (signal < 0) {
		return (unsigned char) 0;
	}
	return (unsigned char) floor(signal);
}

/**
 * Signal en 8 bits (amplitude de 0 à 255 avec 127 pour 0)
 * @param data8
 * @return
 */
double unsignedCharToDouble(unsigned char data8) {
	return (double) data8;
}

/*
 * Main ------------------------------------------------------------------
 */

int main() {
	/**
	 * Création d'un accord La majeur à partir du La440
	 */
	cout << "Création du signal de A4 majeur sur 6s.\n";
	Wave la440;
	la440.read("../sons/la440.wav");

	for (int i = 0; i < 10; i++) {

	}
	return 0;
}
