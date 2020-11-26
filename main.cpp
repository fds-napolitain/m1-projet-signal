#include <iostream>
#include <cmath>
#include "Wave.h"

using namespace std;

#define FREQ_ECHANTILLONAGE 44100
#define FREQ_LA 440

// incrémente par demi ton, 12 pour un octave
double incrementSemiTone(double freq, double i) {
	return freq * pow((pow(2, 1/12)), i);
}

unsigned char doubleToUnsignedChar(double signal) {
	if (signal > 255) {
		return (unsigned char) 255;
	} else if (signal < 0) {
		return (unsigned char) 0;
	}
	return (unsigned char) floor(signal);
}

void DFT(double *signal, double *partie_reelle, double *partie_imaginaire, int N) {
	double val, multiple ;
	double deux_pi_N = 2.0 * M_PI / (double)N ;
	double *pt_r, *pt_i, *pt, *fin, *fin_r ;

	pt_r = partie_reelle ;
	pt_i = partie_imaginaire ;
	fin_r = pt_r + N ;
	multiple = 0.0 ;
	while( pt_r < fin_r ) {
		(*pt_r) = 0.0 ;
		(*pt_i) = 0.0 ;
		pt = signal ; fin = pt + N ;
		val = 0.0 ;
		while( pt < fin ) {
			(*pt_r) += (*pt) * cos(val) ;
			(*pt_r) -= (*pt) * sin(val) ;
			val += multiple ;
			pt++ ;
		}
		multiple += deux_pi_N ;
		pt_r++ ; pt_i++ ;
	}
}

void dft()

int main() {
	/**
	 * Créer un La 440
	 */
	Wave la440;
	long int data_nb = 50000;
	unsigned char data8[data_nb];
	short channel_nb = 1;
	int duree = 6; // secondes
	la440 = Wave(data8, FREQ_ECHANTILLONAGE*duree, channel_nb, FREQ_ECHANTILLONAGE);
	return 0;
}
