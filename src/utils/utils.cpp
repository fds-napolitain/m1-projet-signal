#include <math.h>
#include <cstdio>
#include "utils.hpp"

unsigned char normalize(double signal) {
	return (signal + 1.0) * 127.5;
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
