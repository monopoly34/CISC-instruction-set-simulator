//
// Created by paul on 5/9/26.
//

#include "Registers.h"

void Registers::setRegister(int reg, uint16_t value) {
    if (reg >= 0 && reg < RegisterCount) {
        registers[reg] = value;
    }
}

uint16_t Registers::getRegister(int reg) const {
    if (reg >= 0 && reg < RegisterCount) {
        return registers[reg];
    }
    return 0;
}

void Registers::setIP(uint16_t value) {
    if (value % 2 != 0) {
        std::cerr << "Value is not even!" << std::endl;
        return;
    }
    IP = value;
}

uint16_t Registers::getIP() const {
    return IP;
}

void Registers::setFlag(FlagsBits flag, bool set) {
    //set flag
    if (set == true) {
        FLAGS |= flag;
    }
    //reset flag
    else {
        FLAGS &= ~flag;
    }
}

bool Registers::getFlag(FlagsBits flag) const {
    return (FLAGS & flag) != 0;
}

uint16_t Registers::getFlags() const {
    return FLAGS;
}

void Registers::printRegisters() const {
    std::cout << "Registers:" << std::endl;
    for (int i = 0; i < RegisterCount; i++) {
        std::cout << "Register " << i << ": 0x" << std::hex << std::setw(3) << std::setfill('0') << registers[i] << std::endl;
    }
    std::cout << "IP: 0x" << std::hex << std::setw(3) << std::setfill('0') << IP << std::endl;
    std::cout << "FLAGS: 0x" << std::hex << std::setw(3) << std::setfill('0') << FLAGS << std::endl;
}

void Registers::incrementIP() {
    IP += 2;
}









