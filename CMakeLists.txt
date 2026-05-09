cmake_minimum_required(VERSION 4.1.2)
project(CISC_instruction_set_simulator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CISC_instruction_set_simulator
        CPU.cpp
        CPU.h
        Memory.cpp
        Memory.h
        InstructionFetch.cpp
        InstructionFetch.h
        DecodeInstruction.cpp
        DecodeInstruction.h
        LoadStore.cpp
        LoadStore.h
        Execute.cpp
        Execute.h
        Interfaces.h
        Registers.cpp
        Registers.h)
