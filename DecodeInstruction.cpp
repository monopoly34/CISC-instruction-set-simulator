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
