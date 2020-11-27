#ifndef M1_PROJET_SIGNAL_UTILS_H
#define M1_PROJET_SIGNAL_UTILS_H

#define FREQ_ECHANTILLONAGE 44100.0
#define FREQ_A4 440.0

/**
 * [-1, 1] -> [0, 255]
 * @param signal
 * @return
 */
unsigned char normalize(double signal);

void Normalisation(double *signal, int N);

#endif //M1_PROJET_SIGNAL_UTILS_H
