//
// Created by Maxime Boucher on 03/12/2020.
//

#include "Instrument.h"


Instrument::Instrument() {
}

void Instrument::addInstrument(char* name, char* expression) {
	instruments.insert(make_pair(name, expression));
}
