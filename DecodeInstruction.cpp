#include "DecodeInstruction.h"

void DecodeInstruction::decode(const std::vector<uint16_t> &words) {
    original_words = words;
    if (words.size() == 0) return;

    opcode = (words[0] >> 10) & 0x3F;
    src1 = (words[0] >> 5) & 0x1F;
    src2 = words[0] & 0x1F;


}

void DecodeInstruction::send_data_to_execute(uint16_t &exopcode, uint16_t &exsrc1, uint16_t &exsrc2) {
    exopcode = opcode;
    exsrc1 = src1;
    exsrc2 = src2;
}
#include <iostream>
#include <iomanip>

using namespace std;

DecodeInstruction::DecodeInstruction(IExecuteInterface* ex) : ex_interface(ex) {}

void DecodeInstruction::decode_instruction(uint64_t fetch_window) {
    // initializam cu 0
    DecodedInstruction instr = {0};

    // primii 16 biti, unde se afla src1, src2 si opcode
    uint16_t header = fetch_window & 0xFFFF;

    // cei mai nesemnificativi 5 biti sunt src2
    instr.src2_type = header & 0x1F;

    // cei 5 biti din mijloc (dupa cei 5 care sunt src2) sunt src1
    instr.src1_type = (header >> 5) & 0x1F;

    // cei mai semnificativi 6 biti sunt opcode
    instr.opcode = (header >> 10) & 0x3F;

    instr.size_in_words = 1;

    cout << "opcode: 0x" << hex << (int)instr.opcode
         << " | src1: 0x" << (int)instr.src1_type
         << " | src2: 0x" << (int)instr.src2_type << dec << "\n";

    cout << "instructiunea ocupa " << (int)instr.size_in_words << " cuvinte.\n";

    send_data_to_execute(instr);
}

void DecodeInstruction::send_data_to_execute(const DecodedInstruction& instr) {
    ex_interface->execute_instruction(instr);
}
