#include "CPU.h"
#include "InstructionFetch.h"
#include "DecodeInstruction.h"
#include "Execute.h"
#include "LoadStore.h"

// bob the builder (constructor)
CPU::CPU(IMemoryInterface *memInterface) : current_cycle(0) {
    // LoadStore este conectat la memoria externa prin interfata acesteia
    loadStoreStage = new LoadStore(memInterface);

    // Execute are nevoie de date de la LoadStore
    executeStage = new Execute(loadStoreStage);

    // DecodeInstruction trimite instructiunea catre Execute
    decodeStage = new DecodeInstruction(executeStage);

    // Fetch are nevoie de DecodeInstruction sa trimita date si de LoadStoreStage sa ceara date din memorie
    fetchStage = new InstructionFetch(decodeStage, loadStoreStage);
}

// destructor
CPU::~CPU() {
    delete fetchStage;
    delete decodeStage;
    delete executeStage;
    delete loadStoreStage;
}

void CPU::tick() {
    current_cycle++;

    if (fetchStage) {
        fetchStage->instruction_fetch();
    }
}

uint64_t CPU::get_current_cycle() const {
    return current_cycle;
}

void CPU::boot_pipeline() {
    pipeline.emplace_back(&DecodeInstruction::run_loop, decodeStage);
    pipeline.emplace_back(&InstructionFetch::run_loop, fetchStage);

    for (auto& t: pipeline) {
        if (t.joinable()) {
            t.join();
        }
    }
}

