#ifndef CISC_INSTRUCTION_SET_SIMULATOR_MEMORY_H
#define CISC_INSTRUCTION_SET_SIMULATOR_MEMORY_H

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

class Memory {
public:
    void AccessMemory() override {
        cout << "memory: AccesMemory() executat";
    }
};



#endif //CISC_INSTRUCTION_SET_SIMULATOR_MEMORY_H
