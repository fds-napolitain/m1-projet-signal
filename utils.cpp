#include <cmath>
#include "utils.h"

double unsignedCharToDouble(unsigned char data8) {
	return (double) data8;
}

unsigned char doubleToUnsignedChar(double signal) {
	if (signal > 255) {
		return (unsigned char) 255;
	} else if (signal < 0) {
		return (unsigned char) 0;
	}
	return (unsigned char) floor(signal);
}
