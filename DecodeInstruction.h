#ifndef CISC_INSTRUCTION_SET_SIMULATOR_DECODEINSTRUCTION_H
#define CISC_INSTRUCTION_SET_SIMULATOR_DECODEINSTRUCTION_H

#include <cstdint>
#include <vector>
#include "Interfaces.h"

class DecodeInstruction : public IDecodeInterface {
    IExecuteInterface* ex_interface;

class DecodeInstruction {
private:
    uint16_t opcode;
    uint16_t src1;
    uint16_t src2;

    uint16_t length; // 1, 2, 3 words
    std::vector<uint16_t> original_words;

    DecodeInstruction() : opcode(0), src1(0), src2(0), length(0) {}

    void decode(const std::vector<uint16_t> &words);

public:
    void send_data_to_execute(uint16_t &exopcode, uint16_t &exsrc1, uint16_t &exsrc2);

};
public:
    DecodeInstruction(IExecuteInterface* ex);

    // primeste fetch_window de 64 de biti de la Fetch
    void decode_instruction(uint64_t fetch_window) override;

    // utilitar pentru a trimite datele mai departe
    void send_data_to_execute(const DecodedInstruction& instruction);
};

#endif //CISC_INSTRUCTION_SET_SIMULATOR_DECODEINSTRUCTION_H
