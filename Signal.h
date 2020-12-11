#ifndef M1_PROJET_SIGNAL_SIGNAL_H
#define M1_PROJET_SIGNAL_SIGNAL_H

#include <vector>
#include "Tone.h"

class Signal {
public:
	double FREQ_ECHANTILLONNAGE = 44100;
	int N = 0; // taille du signal (duree * FREQ_ECHANTILLONNAGE
	int duree; // durée du signal
	std::vector<double> signal; // tableau d'amplitudes sur le temps
	std::vector<double> a; // partie réelle
	std::vector<double> b; // partie imaginaire

	/**
	 * Consructeur utilisé pour lire un Signal à partir d'un fichier.
	 * @param path chemin vers un fichier
	 */
	Signal(char* path);

	/**
	 * Constructeur utilisé pour créer un Signal (pour ensuite l'écrire dans un fichier).
	 * @param duree durée du signal à créer (échantillonnage fixe)
	 */
	Signal(int duree);

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
	int fft(int dir);

	/**
	 * Rajouter une note à un signal à partir d'une fréquence, d'une amplitude, d'un début et d'une fin.
	 * @param freq fréquence entre 0 et FREQ_ECHANTILLONNAGE
	 * @param amplitude entre -1 et 1
	 * @param start entre 0 et end
	 * @param end entre start et duree
	 */
	void addTone(Tone tone, double start, double end);

	void addTones(std::vector<Tone> tones, double start, double end);

	/**
	 * Filtre passe-bas qui applique une atténuation à partir d'une certaine fréquence.
	 * Utilise le domaine fréquenciel donc
	 * @param fc 3000 hz pour fc >= 3000
	 */
	void filter_low_pass(double fc);

	void filter_butterworth(double *input, double *output, double N, double alpha);
};


#endif //M1_PROJET_SIGNAL_SIGNAL_H
