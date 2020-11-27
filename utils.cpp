#include <cmath>
#include "utils.h"

double unsignedCharToDouble(unsigned char data8) {
	return (double) data8;
}

unsigned char doubleToUnsignedChar(double signal) {
	if (signal > 255) {
		return (unsigned char) 255;
	} else if (signal < 0) {
		return (unsigned char) 0;
	}
	return (unsigned char) floor(signal);
}

void Normalisation(double *signal, int N) {
	double mini, maxi, delta ;
	double *pt, *fin ;
	pt = signal ; fin = pt + N ;
	mini = (*pt) ; maxi = mini ;
	while(pt<fin) {
		maxi = maxi<(*pt) ? (*pt) : maxi ;
		mini = mini>(*pt) ? (*pt) : mini ;
		pt++ ;
	}
	delta = maxi - mini ;
	if(delta > 1e-16) delta = 1.0 / delta ;
	pt = signal ; fin = pt + N ;
	while(pt<fin) {
		(*pt) = ((*pt) - mini) * delta ;
		pt++ ;
	}
}
