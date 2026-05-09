#ifndef CISC_INSTRUCTION_SET_SIMULATOR_REGISTERS_H
#define CISC_INSTRUCTION_SET_SIMULATOR_REGISTERS_H

#include <vector>
#include <cstdint>
#include <iomanip>
#include <iostream>

class Registers {
    private:
    static constexpr int RegisterCount = 8;
    std::vector<uint16_t> registers;
    uint16_t IP; // Instruction Pointer
    uint16_t FLAGS; // 0 -> Z, 1 -> E, 2 -> G
    uint16_t SP; // Stack Pointer

    enum FlagsBits {
        ZERO = 0x001,
        EQUAL = 0x002,
        GREATER = 0x004,
    };

    Registers() : registers(RegisterCount, 0), IP(0), FLAGS(0), SP(0xFFF) {}
    void setRegister(int reg, uint16_t value);
    uint16_t getRegister(int reg) const;
    void setIP(uint16_t value);
    uint16_t getIP() const;
    void setFlag(FlagsBits flag, bool set);
    bool getFlag(FlagsBits flag) const;
    uint16_t getFlags() const;
    void printRegisters() const;
};


#endif //CISC_INSTRUCTION_SET_SIMULATOR_REGISTERS_H