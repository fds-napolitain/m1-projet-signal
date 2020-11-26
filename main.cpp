#include <iostream>
#include "Wave.h"

using namespace std;

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
