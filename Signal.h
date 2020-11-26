#ifndef M1_PROJET_SIGNAL_SIGNAL_H
#define M1_PROJET_SIGNAL_SIGNAL_H

#define CHANNELS_NB 1
#define FREQ_ECHANTILLONAGE 44100
#define FREQ_A4 440

class Signal {
private:
	int N;
	double* signal;
	double* a;
	double* b;
public:
/**
	 * Pour plus d'info sur la transformation de fourier voir :
	 * https://betterexplained.com/articles/an-interactive-guide-to-the-fourier-transform/
	 * @param signal tableau d'amplitudes du signal
	 * @param a partie réelle
	 * @param b partie imaginaire
	 * @param N N
	 */
	void dft(double* signal, double* a, double* b, int N);

	/**
	 * Transformation de fourier inverse.
	 * @param signal
	 * @param a partie réelle
	 * @param b partie imaginaire
	 * @param N
	 */
	void idft(double* signal, double* a, double* b, int N);

	/**
	 * Renvoit une note avec une tonalité changée (par demi ton)
	 * @param freq fréquence en hertz
	 * @param i nombre de demi ton (positif ou négatif)
	 * @return freq fréquence en hertz
	 */
	double incrementSemiTone(double freq, double i);
};


#endif //M1_PROJET_SIGNAL_SIGNAL_H
