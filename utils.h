#ifndef M1_PROJET_SIGNAL_UTILS_H
#define M1_PROJET_SIGNAL_UTILS_H

#define FREQ_A4 440.0

/**
 * [-1, 1] -> [0, 255]
 * @param signal
 * @return
 */
unsigned char normalize(double signal);

/**
 * Fonction du prof
 * @param signal
 * @param N
 */
void Normalisation(double *signal, int N);

/**
 * Renvoit une note avec une tonalité changée (par demi ton)
 * @param freq fréquence en hertz
 * @param i nombre de demi ton (positif ou négatif)
 * @return freq fréquence en hertz
 */
double incrementSemiTone(double freq, double i);

#endif //M1_PROJET_SIGNAL_UTILS_H
