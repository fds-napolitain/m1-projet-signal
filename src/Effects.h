#ifndef M1_PROJET_SIGNAL_EFFECTS_H
#define M1_PROJET_SIGNAL_EFFECTS_H


#include "Signal.h"

class Effects {
public:
	/**
	 * fonction passe bas
	 * @param fc fréquence a couper
	 * @return
	 */
	static double low_pass(double fc);

	/**
	 * fonction passe bas
	 * @param fc fréquence a couper
	 * @return
	 */
	static double low_pass(double fc, double i);
};


#endif //M1_PROJET_SIGNAL_EFFECTS_H
