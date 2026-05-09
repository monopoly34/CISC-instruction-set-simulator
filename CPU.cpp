#include "CPU.h"
#include "InstructionFetch.h"
#include "DecodeInstruction.h"
#include "Execute.h"
#include "LoadStore.h"

// bob the builder (constructor)
CPU::CPU(IMemoryInterface *memInterface) {
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

void CPU::clock_cycle() {
    fetchStage -> instruction_fetch();
}
