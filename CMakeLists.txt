cmake_minimum_required(VERSION 3.17)
project(m1_projet_signal)

set(CMAKE_CXX_STANDARD 20)

add_executable(m1_projet_signal main.cpp src/utils/Wave.cpp src/utils/Wave.h src/Signal.cpp src/Signal.h src/utils/utils.cpp src/utils/utils.h src/Tone.cpp src/Tone.h src/Instrument.cpp src/Instrument.h src/Track.cpp src/Track.h src/Effects.cpp src/Effects.h)