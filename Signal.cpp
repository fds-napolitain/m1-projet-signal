#include <cmath>
#include "Signal.h"
#include "Wave.h"
#include "utils.h"

Signal::Signal(char *path) {
	unsigned char* data8 = NULL;
	Wave wave(data8);
	wave.read(path);
	wave.getData8(&Signal::signal, sizeof(Signal::signal))
}

void Signal::dft(double *signal, double *a, double *b, int N) {
	for (int k = 0; k < N; k++) {
		a[k] = 0;
		b[k] = 0;
		for (int n = 0; n < N; n++) {
			a[k] += signal[n]*cos(2*M_PI*(k*n/N));
			b[k] -= signal[n]*sin(2*M_PI*(k*n/N));
		}
	}
}

void Signal::idft(double *signal, double *a, double *b, int N) {
	for (int n = 0; n < N; n++) {
		signal[n] = 0;
		for (int k = 0; k < N; k++) {
			signal[n] += a[k]*cos(2*M_PI*(k*n/N)) - b[k]*sin(2*M_PI*(k*n/N));
		}
		signal[n] = 1/N*signal[n];
	}
}

double Signal::incrementSemiTone(double freq, double i) {
	return freq * pow((pow(2, 1/12)), i);
}
