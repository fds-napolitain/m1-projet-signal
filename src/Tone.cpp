#include <cmath>
#include "Tone.h"

Tone::Tone(char *tone) {
	frequency = 440.0;
	amplitude = 1.0;
	phase = 0.0;
	int coef = 0;
	int multiplier[] = {-9, -7, -5, -4, -2, 0, 2};
	char* current = (char*) "A4";
	if (tone[0] == 'C') { // changer de note
		coef += multiplier[0];
	} else if (tone[0] == 'D') {
		coef += multiplier[1];
	} else if (tone[0] == 'E') {
		coef += multiplier[2];
	} else if (tone[0] == 'F') {
		coef += multiplier[3];
	} else if (tone[0] == 'G') {
		coef += multiplier[4];
	} else if (tone[0] == 'A') {
		coef += multiplier[5];
	} else if (tone[0] == 'B') {
		coef += multiplier[6];
	}
	for (int i = 0; i < 7; ++i) {
		multiplier[i] -= coef;
	}
	if (tone[1] != current[1]) { // changer d'octave
		coef += 12 * ((int) tone[1] - (int) current[1]);
	}
	current = tone;
	if (coef != 0) {
		incrementSemiTone(frequency, (double) coef);
	}
}

void Tone::incrementSemiTone(double freq, double i) {
	this->frequency = freq * pow(2.0, 1.0/12.0*i);
}
