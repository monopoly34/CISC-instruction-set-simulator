#include "Memory.h"

// Only write at even address
bool Memory::write(uint16_t address, uint16_t value) {
    if (address % 2 != 0) {
        std::cerr << "Address is not even!" << std::endl;
        return false;
    }
    if (address < SIZE_MEMORY) {
        data[address] = value;
        return true;
    }
    return false;
}

// Read one word
uint16_t Memory::read(uint16_t address) {
    uint16_t Memory::read(uint16_t address) {
    if (address % 2 != 0) {
        std::cerr << "Address is not even!" << std::endl;
        return 0;
    }
    if (address < SIZE_MEMORY) {
        return data[address];
    }
    return 0;
}

// Read up to 4 words
std::vector<uint16_t> Memory::readMultiple(uint16_t address, int count) {
    std::vector<uint16_t> result;
    if (count > 4) {
        count = 4;
    }
    if (address % 2 != 0) {
        std::cerr << "Address is not even!" << std::endl;
        return result;
    }

    for (int i = 0; i < count; i++) {
        if (address + (i * 2) < Memory::SIZE_MEMORY) {
            result.push_back(data[address + (i * 2)]);
        }
    }
    return result;
}

void Memory::printMemory(uint16_t start, uint16_t end) const {
    if (start % 2 != 0) {
        std::cerr << "Address is not even! Incrementing to closest even address." << std::endl;
        start++;
    }

    std::cout << "--- MEMORY --- " << std::endl;
    for (uint16_t address = start; address < end; address += 2) {
        std::cout << "0x" << std::hex << std::setw(3) << std::setfill('0') << address << ": " << std::setw(3) << data[address] << std::endl;
    }
}
