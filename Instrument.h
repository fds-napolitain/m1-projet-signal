//
// Created by Maxime Boucher on 03/12/2020.
//

#ifndef M1_PROJET_SIGNAL_INSTRUMENT_H
#define M1_PROJET_SIGNAL_INSTRUMENT_H

using namespace std;

#include "unordered_map"

class Instrument {
public:
	unordered_map<char*, char*> instruments; // instrument dans une hashmap<nom, fn>

	Instrument();
	void addInstrument(char* name, char* expression);
};


#endif //M1_PROJET_SIGNAL_INSTRUMENT_H
