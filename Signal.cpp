#include <math.h>
#include "Signal.h"
#include "Wave.h"
#include "utils.h"

Signal::Signal(char *path) {
	unsigned char* data8;
	Wave wave = Wave();
	wave.read(path);
	wave.getData8(&data8, &(Signal::N));
	Signal::signal = (double*) malloc(N*sizeof(double));
	Signal::a = (double*) malloc(N*sizeof(double));
	Signal::b = (double*) malloc(N*sizeof(double));
	for (int i = 0; i < N; ++i) {
		Signal::signal[i] = (double) data8[i]/127.5 - 1.0;
	}
}

Signal::Signal(int duree) {
	Signal::N = duree * FREQ_ECHANTILLONNAGE;
	Signal::duree = duree;
	Signal::signal = (double*) malloc(N*sizeof(double));
	Signal::a = (double*) malloc(N*sizeof(double));
	Signal::b = (double*) malloc(N*sizeof(double));
}

Signal::Signal(const Signal &oldSignal) noexcept {
	Signal newSignal = Signal(oldSignal.N);
	for (int i = 0; i < sizeof(oldSignal.N); ++i) {
		newSignal.signal[i] = oldSignal.signal[i];
		newSignal.a[i] = oldSignal.a[i];
		newSignal.b[i] = oldSignal.b[i];
	}
}

Signal::~Signal() {
	free(Signal::signal);
	free(Signal::a);
	free(Signal::b);
}

void Signal::write_signal(char *path) {
	unsigned char data8[N];
	for (int i = 0; i < N; ++i) {
		data8[i] = normalize(Signal::signal[i]);
	}
	Wave wave = Wave(data8, Signal::N, 1, FREQ_ECHANTILLONNAGE);
	wave.write(path);
}

void Signal::dft() {
	double deuxPiN = 2.0 * M_PI / (double) N;
	double omega, theta = 0.0;
	for (int k = 0; k < N; k++) {
		omega = deuxPiN * (double) k;
		a[k] = 0.0;
		b[k] = 0.0;
		for (int n = 0; n < N; n++) {
			theta = omega * (double) n;
			a[k] += signal[n] * cos(theta);
			b[k] -= signal[n] * sin(theta);
		}
	}
}

void Signal::idft() {
	double deuxPiN = 2.0 * M_PI / (double) N;
	double omega, theta = 0.0;
	for (int n = 0; n < N; n++) {
		omega = deuxPiN * (double) n;
		signal[n] = 0.0;
		for (int k = 0; k < N; k++) {
			theta = omega * (double) k;
			signal[n] += 1 / (double) N * (a[k]*cos(theta) - b[k]*sin(theta));
		}
	}
}

// TODO: pas encore adapté pour ma class Signal
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
		for (j=0; j<l1; j++) {
			for (i=j; i<n; i+=l2) {
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

void Signal::addTone(double freq, double amplitude, double start, double end) {
	double tone = 2.0 * M_PI * freq / (double) FREQ_ECHANTILLONNAGE;
	int fin = end*FREQ_ECHANTILLONNAGE;
	for (int i = start*FREQ_ECHANTILLONNAGE; i < fin; ++i) {
		signal[i] = sin((double) i * tone);
	}
}

void Signal::lowPass(double freq, double attenuation) {
	int r = 1 - attenuation;
	dft();
	for (int i = freq+1; i < N; ++i) {
		a[i] = a[i] * r;
		b[i] = b[i] * r;
	}
	idft();
}