#ifndef CISC_INSTRUCTION_SET_SIMULATOR_CPU_H
#define CISC_INSTRUCTION_SET_SIMULATOR_CPU_H
#include "Memory.h"
#include "Registers.h"

#include <cstdint>
#include <thread>
#include <vector>

// forward declarations
class InstructionFetch;
class DecodeInstruction;
class Execute;
class LoadStore;
class IMemoryInterface;

class CPU {
    InstructionFetch *fetchStage;
    DecodeInstruction *decodeStage;
    Execute *executeStage;
    LoadStore *loadStoreStage;
    Memory memory;
    Registers registers;
    uint16_t opcode;
    uint16_t src1;
    uint16_t src2;

    uint64_t current_cycle;

    std::vector<std::thread> pipeline;
public:
    // constructor (the only parameter is the extern memory interface)
    CPU(IMemoryInterface *memInterface);

    // destructor
    ~CPU();

    // method to simulate a clock cycle
    void clock_cycle();

    void execute(DecodeInstruction &inst);

private:
    void executeADD(const DecodeInstruction &inst);
    void executeSUB(const DecodeInstruction &inst);
    void executeMOV(const DecodeInstruction &inst);
    void executeMUL(const DecodeInstruction &inst);
    void executeDIV(const DecodeInstruction &inst);
    void executeCMP(const DecodeInstruction &inst);
    void executeJMP(const DecodeInstruction &inst);
    void executeJE(const DecodeInstruction &inst);
    void executeJL(const DecodeInstruction &inst);
    void executeJG(const DecodeInstruction &inst);
    void executeJZ(const DecodeInstruction &inst);
    void executeCALL(const DecodeInstruction &inst);
    void executeRET(const DecodeInstruction &inst);
    void executeEND(const DecodeInstruction &inst);
    void executePUSH(const DecodeInstruction &inst);
    void executePOP(const DecodeInstruction &inst);

    // functie carea avanseaza clock ul cu un ciclu
    void tick();

    // functie pentru a vedea clock ul curent
    uint64_t get_current_cycle() const;

    void boot_pipeline();
};

#endif //CISC_INSTRUCTION_SET_SIMULATOR_CPU_H
