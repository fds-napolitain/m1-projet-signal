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
	std::vector<double> re; // partie réelle
	std::vector<double> im; // partie imaginaire
	double bin_width; // taille du bin (par exemple, 0.3hz) utilisé pour trouver re partir d'une fréquence de coupure la fréquence de coupure numérique (bin)


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
	 *	allocate re new signal of nm=2^m values
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

	/**
	 * Ajouter plusieurs notes sous formes d'accord
	 * @param tones
	 * @param start
	 * @param end
	 */
	void addTones(std::vector<Tone> tones, double start, double end);

	/**
	 * Filtre passe-bas qui applique une atténuation à partir d'une certaine fréquence
	 * Plus l'équation est de fort degré plus l'atténuation est rapide
	 * @param fc fréquence de coupure, ex 300 hz
	 */
	void filter_butterworth(double fc);

	/**
	 * Enregistrer le signal sous un format customisé qui permet de compresser sans perte le signal.
	 * Utilise FFT pour l'analyse fréquenciel
	 * @param path
	 */
	void write_huffman(char *path);

	/**
	 * Lire le signal sous un format customisé qui permet de compresser sans perte le signal.
	 * Utilise FFT pour l'analyse fréquenciel
	 * @param path
	 */
	void read_huffman(char *path);

	/**
	 * Filtre applique une coupure à partir d'une certaine fréquence.
	 * Utilise le domaine fréquenciel donc
	 * @param fc fréquence de coupure
	 * @param attenuation 1 => coupe tout
	 */
	void filter_low_pass(double fc, double attenuation);

	/**
	 * Filtre applique une coupure à partir d'une certaine fréquence.
	 * Utilise le domaine fréquenciel donc
	 * @param fc fréquence de coupure
	 * @param attenuation 1 => coupe tout
	 */
	void filter_high_pass(double fc, double attenuation);

	/**
	 * Filtre passe bande entre fc1 et fc2.
	 * @param fc1
	 * @param fc2
	 * @param attenuation 1 => coupe tout
	 */
	void filter_pass_band(double fc1, double fc2, double attenuation);

	void filter_reject_band(double fc1, double fc2, double attenuation);

	void delay(double n);
};


#endif //M1_PROJET_SIGNAL_SIGNAL_H
