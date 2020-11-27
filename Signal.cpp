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
			a[k] += signal[n]*cos(2.0*M_PI*((double)k*(double)n/(double)N));
			b[k] -= signal[n]*sin(2.0*M_PI*((double)k*(double)n/(double)N));
		}
	}
}

/**
 *	This fft has been proposed by Paul Bourke
 *	http://paulbourke.net/miscellaneous/dft/
 *	This computes an in-place complex-to-complex fft
 *	x and y are the real and imaginary arrays of 2^m points.
 *	dir =  1 gives forward transform
 *	dir = -1 gives reverse transform
 *	You MUST compute first the value m such that
 *	2^(m-1) < n (size of your signal) <= 2^m
 *	allocate a new signal of nm=2^m values
 *	then fill the n first values of this new signal
 *   with your signal and fill the rest with 0
 *	WARNING : you must pass m, not nm !!!
 */
int Signal::fft(int dir, int m, double *x, double *y) {
	int n,i,i1,j,k,i2,l,l1,l2;
	double c1,c2,tx,ty,t1,t2,u1,u2,z;
	/* Calculate the number of points */
	n = 1;
	for (i=0;i<m;i++)
		n *= 2;
	/* Do the bit reversal */
	i2 = n >> 1;
	j = 0;
	for (i=0;i<n-1;i++) {
		if (i < j) {
			tx = x[i];
			ty = y[i];
			x[i] = x[j];
			y[i] = y[j];
			x[j] = tx;
			y[j] = ty;
		}
		k = i2;
		while (k <= j) {
			j -= k;
			k >>= 1;
		}
		j += k;
	}

	/* Compute the fft */
	c1 = -1.0;
	c2 = 0.0;
	l2 = 1;
	for (l=0;l<m;l++) {
		l1 = l2;
		l2 <<= 1;
		u1 = 1.0;
		u2 = 0.0;
		for (j=0;j<l1;j++) {
			for (i=j;i<n;i+=l2) {
				i1 = i + l1;
				t1 = u1 * x[i1] - u2 * y[i1];
				t2 = u1 * y[i1] + u2 * x[i1];
				x[i1] = x[i] - t1;
				y[i1] = y[i] - t2;
				x[i] += t1;
				y[i] += t2;
			}
			z =  u1 * c1 - u2 * c2;
			u2 = u1 * c2 + u2 * c1;
			u1 = z;
		}
		c2 = sqrt((1.0 - c1) / 2.0);
		if (dir == 1)
			c2 = -c2;
		c1 = sqrt((1.0 + c1) / 2.0);
	}
	/* Scaling for forward transform */
	if (dir == 1) {
		for (i=0;i<n;i++) {
			x[i] /= n;
			y[i] /= n;
		}
	}
	return(1);
}

void Signal::idft(double *signal, double *a, double *b, int N) {
	for (int n = 0; n < N; n++) {
		signal[n] = 0;
		for (int k = 0; k < N; k++) {
			signal[n] += a[k]*cos(2*M_PI*((double)k*(double)n/(double)N)) - b[k]*sin(2*M_PI*((double)k*(double)n/(double)N));
		}
		signal[n] = 1.0/N*signal[n];
	}
}

double Signal::incrementSemiTone(double freq, double i) {
	return freq * pow((pow(2, 1/12)), i);
}
