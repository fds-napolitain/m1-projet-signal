cmake_minimum_required(VERSION 3.17)
project(m1_projet_signal)

set(CMAKE_CXX_STANDARD 20)

add_executable(m1_projet_signal main.cpp Wave.cpp Wave.h Signal.cpp Signal.h utils.cpp utils.h Tone.cpp Tone.h Instrument.cpp Instrument.h Track.cpp Track.h)