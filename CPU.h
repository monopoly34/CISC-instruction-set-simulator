#ifndef CISC_INSTRUCTION_SET_SIMULATOR_CPU_H
#define CISC_INSTRUCTION_SET_SIMULATOR_CPU_H

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

    uint64_t current_cycle;

    std::vector<std::thread> pipeline;
public:
    // constructor (the only parameter is the extern memory interface)
    CPU(IMemoryInterface *memInterface);

    // destructor
    ~CPU();

    // functie carea avanseaza clock ul cu un ciclu
    void tick();

    // functie pentru a vedea clock ul curent
    uint64_t get_current_cycle() const;

    void boot_pipeline();
};

#endif //CISC_INSTRUCTION_SET_SIMULATOR_CPU_H
