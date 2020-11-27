#ifndef M1_PROJET_SIGNAL_UTILS_H
#define M1_PROJET_SIGNAL_UTILS_H

/**
 * Signal en 8 bits (amplitude de 0 à 255 avec 127 pour 0)
 * @param signal
 * @return
 */
unsigned char doubleToUnsignedChar(double signal);

/**
 * Signal en 8 bits (amplitude de 0 à 255 avec 127 pour 0)
 * @param data8
 * @return
 */
double unsignedCharToDouble(unsigned char data8);

void Normalisation(double *signal, int N);

#endif //M1_PROJET_SIGNAL_UTILS_H
