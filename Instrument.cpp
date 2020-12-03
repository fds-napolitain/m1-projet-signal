//
// Created by Maxime Boucher on 03/12/2020.
//

#include "Instrument.h"


Instrument::Instrument() {
	instruments = unordered_map<char*, char*>();
}

void Instrument::addInstrument(char* name, char* expression) {
	instruments.insert(name, expression);
}
