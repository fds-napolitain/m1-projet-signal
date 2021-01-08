//
// Created by Maxime Boucher on 03/12/2020.
//

#include "Instrument.hpp"


Instrument::Instrument() {
}

void Instrument::addInstrument(char* name, char* expression) {
	instruments.insert(std::make_pair(name, expression));
}
