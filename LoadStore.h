#ifndef CISC_INSTRUCTION_SET_SIMULATOR_LOADSTOREDATA_H
#define CISC_INSTRUCTION_SET_SIMULATOR_LOADSTOREDATA_H

#include "Interfaces.h"
#include <cstdint>

class LoadStore : public ILoadStoreInterface {
    IMemoryInterface *memory_interface;

public:
    // constructorul
    LoadStore(IMemoryInterface *memory);

    // punctul de intrare pentru Fetch & Execute
    uint64_t memory_buffer(uint16_t address, MemOperations op, uint16_t write_data) override;

    // trimite cererea catre memorie
    uint64_t request_to_memory(uint16_t address, MemOperations op, uint16_t write_data);

    // proceseaza daele primite de la memorie
    uint64_t receive_memory_data(uint64_t raw_data);
};



#endif //CISC_INSTRUCTION_SET_SIMULATOR_LOADSTOREDATA_H
