#ifndef M1_PROJET_SIGNAL_EFFECTS_HPP
#define M1_PROJET_SIGNAL_EFFECTS_HPP


#include "Signal.hpp"

class Effects {
public:
	/**
	 * fonction passe bas
	 * @param fc fréquence re couper
	 * @return
	 */
	static double low_pass(double fc);
};


#endif //M1_PROJET_SIGNAL_EFFECTS_HPP
