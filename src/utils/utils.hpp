#ifndef M1_PROJET_SIGNAL_UTILS_HPP
#define M1_PROJET_SIGNAL_UTILS_HPP

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

#endif //M1_PROJET_SIGNAL_UTILS_HPP
