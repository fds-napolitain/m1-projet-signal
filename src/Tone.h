#ifndef M1_PROJET_SIGNAL_TONE_H
#define M1_PROJET_SIGNAL_TONE_H

#include <vector>

class Tone {
public:
	double frequency;
	double amplitude;
	double phase;

	/**
	 * Constructeur d'une note, avec frequency comme attribut pour la fréquence.
	 * @param tone sous format "A4"
	 */
	Tone(char *tone);

	/**
	 * Set une note avec une tonalité changée (par demi ton)
	 * @param freq fréquence en hertz
	 * @param i nombre de demi ton (positif ou négatif)
	 */
	void incrementSemiTone(double freq, double i);
};

typedef std::vector<Tone> Tones;

#endif //M1_PROJET_SIGNAL_TONE_H
