#include "CPU.h"
#include <iostream>

#include "InstructionFetch.h"
#include "DecodeInstruction.h"
#include "Execute.h"
#include "LoadStore.h"
#include "Interfaces.h"

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

void CPU::execute(DecodeInstruction &inst) {
    uint16_t opcode;
    uint16_t src1;
    uint16_t src2;
    inst.send_data_to_execute(opcode, src1, src2);
    switch (opcode) {
            case 0x01: executeADD(inst); break;
            case 0x02: executeSUB(inst); break;
            case 0x03: executeMOV(inst); break;
            case 0x04: executeMUL(inst); break;
            case 0x05: executeDIV(inst); break;
            case 0x06: executeCMP(inst); break;
            case 0x07: executeJMP(inst); break;
            case 0x08: executeJE(inst); break;
            case 0x09: executeJL(inst); break;
            case 0x0A: executeJG(inst); break;
            case 0x0B: executeJZ(inst); break;
            case 0x0C: executeCALL(inst); break;
            case 0x0D: executeRET(inst); break;
            case 0x0E: executeEND(inst); break;
            case 0x0F: executePUSH(inst); break;
            case 0x10: executePOP(inst); break;
        default:
            std::cerr << "Unrecognized opcode: " << opcode << std::endl;
    }
}

void CPU::executeADD(const DecodeInstruction &inst) {
    uint16_t var1 = registers.getR
}
