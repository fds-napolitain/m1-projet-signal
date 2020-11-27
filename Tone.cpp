#include <cmath>
#include "Tone.h"

Tone::Tone(char *tone) {
	double freq = 440.0; // A4 default
	int coef = 0;
	if (tone[1] != '4') {
		coef += 12 * ((int) tone[1] - 4);
	}
	switch (tone[0]) {
		case 'C':
			coef -= 9;
			break;
		case 'D':
			coef -= 7;
			break;
		case 'E':
			coef -= 5;
			break;
		case 'F':
			coef -= 4;
			break;
		case 'G':
			coef -= 2;
			break;
		case 'B':
			coef += 2;
			break;
	}
	if (coef != 0) {
		incrementSemiTone(freq, (double) coef);
	}
}

void Tone::incrementSemiTone(double freq, double i) {
	freq = freq * pow(pow(2.0, (1.0/12.0)), i);
}
