#ifndef M1_PROJET_SIGNAL_EFFECTS_H
#define M1_PROJET_SIGNAL_EFFECTS_H


#include "Signal.h"

class Effects {
public:
	/**
	 * fonction passe bas
	 * @param fc fréquence re couper
	 * @return
	 */
	static double low_pass(double fc);
};


#endif //M1_PROJET_SIGNAL_EFFECTS_H
