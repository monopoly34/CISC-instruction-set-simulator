#ifndef CISC_INSTRUCTION_SET_SIMULATOR_MEMORY_H
#define CISC_INSTRUCTION_SET_SIMULATOR_MEMORY_H

#include <vector>
#include <cstdint>
#include <iostream>
#include <iomanip>

class Memory {
private:
    static const uint16_t SIZE_MEMORY = 4096;
    std::vector<uint16_t> data;
    Memory() : data(SIZE_MEMORY, 0) {}

    // Only write at even address
    bool write(uint16_t address, uint16_t value);

    // Read one word
    uint16_t read(uint16_t address);

    // Read up to 4 words
    std::vector<uint16_t> readMultiple(uint16_t address, int count);

    void printMemory(uint16_t start, uint16_t end) const;
};


#endif //CISC_INSTRUCTION_SET_SIMULATOR_MEMORY_H
