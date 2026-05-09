#include "InstructionFetch.h"
#include <iostream>
#include <cstdint>
#include <iomanip>


using namespace std;

// constructor
InstructionFetch::InstructionFetch(IDecodeInterface *decode, ILoadStoreInterface *loadStore)
:  decode_interface(decode), load_store_interface(loadStore), program_counter(0x0000) {

}

// metoda instruction_fetch (pasul 1)
void InstructionFetch::instruction_fetch() {
    cout << "incepe fetch pentru 0x" << hex << setw(4) << setfill('0') << program_counter << dec << "\n";
    request_to_memory();
}

// metoda request_to_memory (pasul 2, cere datele)
void InstructionFetch::request_to_memory() {
    cout << "cer 64-biti de la LoadStore";

    uint64_t fetch_window = load_store_interface->memory_buffer(program_counter, MemOperations::FETCH_64, 0);
    receive_memory_data(fetch_window);
}

// metoda receive_memory_data (pasul 3, primeste datele, le trimite mai departe si avanseaza)
void InstructionFetch::receive_memory_data(uint64_t fetch_window) {
    cout << "am primit fetch window-ul 0x" << hex << setw(16) << setfill('0') << fetch_window << dec << "\n";
    cout << "trimit date catre decode";

    decode_interface->decode_instruction(fetch_window);

    // dupa ce am trimis fereasta, pregatim PC ul pentru urmatorul ciclu
    increment_program_counter();
}

void InstructionFetch::increment_program_counter() {
    program_counter += 8;
}

void InstructionFetch::set_program_counter(uint16_t address) {
    if (address % 2 != 0) {
        cerr << "jump la adresa impara.";
        address--;
    }
    program_counter = address;
}
