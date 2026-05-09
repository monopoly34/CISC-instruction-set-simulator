#ifndef CISC_INSTRUCTION_SET_SIMULATOR_INSTRUCTIONFETCH_H
#define CISC_INSTRUCTION_SET_SIMULATOR_INSTRUCTIONFETCH_H

#include "Interfaces.h"
#include <cstdint>

class InstructionFetch {
    IDecodeInterface *decode_interface;
    ILoadStoreInterface *load_store_interface;

    // adresa curenta a instructiunii
    uint16_t program_counter;

public:
    // constructor
    InstructionFetch(IDecodeInterface *decode, ILoadStoreInterface *loadStore);

    void instruction_fetch();

    // cere date din memorie pe baza PC-ului
    void request_to_memory();

    // primeste cei 64 de biti si ii trimie la Decode
    void receive_memory_data(uint64_t fetch_window);

    // incrementam PC-ul cu 8 (un fetch_window are 4 cuvinte de cate 2 octeti fiecare)
    void increment_program_counter();

    // folosita de Execute cand avem salturi
    void set_program_counter(uint16_t address);
};

#endif //CISC_INSTRUCTION_SET_SIMULATOR_INSTRUCTIONFETCH_H
