#ifndef CISC_INSTRUCTION_SET_SIMULATOR_CPU_H
#define CISC_INSTRUCTION_SET_SIMULATOR_CPU_H

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

public:
    // constructor (the only parameter is the extern memory interface)
    CPU(IMemoryInterface *memInterface);

    // destructor
    ~CPU();

    // method to simulate a clock cycle
    void clock_cycle();
};

#endif //CISC_INSTRUCTION_SET_SIMULATOR_CPU_H
