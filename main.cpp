#include <iostream>
#include <cmath>
#include "Wave.h"

using namespace std;

#define ENDLINE "\n"

#define CHANNELS_NB 1
#define FREQ_ECHANTILLONAGE 44100
#define FREQ_A4 440

/**
 * Renvoit une note avec une tonalité changée (par demi ton)
 * @param freq fréquence en hertz
 * @param i nombre de demi ton (positif ou négatif)
 * @return freq fréquence en hertz
 */
double incrementSemiTone(double freq, double i) {
	return freq * pow((pow(2, 1/12)), i);
}

/**
 *
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
 *
 * @param data8
 * @return
 */
double unsignedCharToDouble(unsigned char data8) {
	return (double) data8;
}

/**
 *
 * @param signal
 * @param partie_reelle
 * @param partie_imaginaire
 * @param N
 */
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


int main() {
	/**
	 * Création d'un accord La majeur à partir du La440
	 */
	cout << "Création du signal de A4 majeur sur 6s." << ENDLINE;
	Wave la440;
	int duree = 6;
	long int data_nb = FREQ_ECHANTILLONAGE*duree;
	unsigned char data8[data_nb];
	la440 = Wave(data8, FREQ_ECHANTILLONAGE*duree, CHANNELS_NB, FREQ_ECHANTILLONAGE);
	la440.read("sons/la440.wav");
	return 0;
}
