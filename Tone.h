#ifndef M1_PROJET_SIGNAL_TONE_H
#define M1_PROJET_SIGNAL_TONE_H


class Tone {
public:
	double freq;

	/**
	 * Constructeur d'une note, avec freq comme attribut pour la fréquence.
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


#endif //M1_PROJET_SIGNAL_TONE_H
