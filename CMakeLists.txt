cmake_minimum_required(VERSION 3.17)
project(m1_projet_signal)

set(CMAKE_CXX_STANDARD 20)

add_executable(m1_projet_signal main.cpp src/utils/Wave.cpp src/utils/Wave.hpp src/Signal.cpp src/Signal.hpp src/utils/utils.cpp src/utils/utils.hpp src/Tone.cpp src/Tone.hpp src/Instrument.cpp src/Instrument.hpp src/Track.cpp src/Track.hpp src/Effects.cpp src/Effects.hpp)