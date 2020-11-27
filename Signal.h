#ifndef M1_PROJET_SIGNAL_SIGNAL_H
#define M1_PROJET_SIGNAL_SIGNAL_H

class Signal {
public:
	int N = 0;
	double* signal; // tableau d'amplitudes sur le temps
	double* a; // partie réelle
	double* b; // partie imaginaire

	/**
	 * Consructeur utilisé pour lire un Signal à partir d'un fichier.
	 * @param path chemin vers un fichier
	 */
	Signal(char* path);

	/**
	 * Constructeur utilisé pour créer un Signal (pour ensuite l'écrire dans un fichier).
	 * @param N taille du signal à créer
	 */
	Signal(int N);

	/**
	 * Constructeur par recopie d'un Signal
	 */
	Signal(const Signal&) noexcept;

	/**
	 * Ecrire un signal dans un fichier.
	 * @param path chemin vers un fichier
	 */
	void write_signal(char *path);

	/**
	 * Pour plus d'info sur la transformation de fourier voir :
	 * https://betterexplained.com/articles/an-interactive-guide-to-the-fourier-transform/
	 */
	void dft();

	/**
	 * Transformation de fourier inverse.
	 */
	void idft();

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
	int fft(int dir, int m, double *x, double *y);

	/**
	 * Renvoit une note avec une tonalité changée (par demi ton)
	 * @param freq fréquence en hertz
	 * @param i nombre de demi ton (positif ou négatif)
	 * @return freq fréquence en hertz
	 */
	void incrementSemiTone(double i);
};


#endif //M1_PROJET_SIGNAL_SIGNAL_H
