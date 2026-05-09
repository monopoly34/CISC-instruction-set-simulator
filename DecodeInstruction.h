#ifndef CISC_INSTRUCTION_SET_SIMULATOR_DECODEINSTRUCTION_H
#define CISC_INSTRUCTION_SET_SIMULATOR_DECODEINSTRUCTION_H

#include "Interfaces.h"

class DecodeInstruction : public IDecodeInterface {
    IExecuteInterface* ex_interface;

public:
    DecodeInstruction(IExecuteInterface* ex);

    // primeste fetch_window de 64 de biti de la Fetch
    void decode_instruction(uint64_t fetch_window) override;

    // utilitar pentru a trimite datele mai departe
    void send_data_to_execute(const DecodedInstruction& instruction);
};

#endif //CISC_INSTRUCTION_SET_SIMULATOR_DECODEINSTRUCTION_H
