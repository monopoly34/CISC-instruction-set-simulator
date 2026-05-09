#include "LoadStore.h"
#include <iostream>
#include <vector>

using namespace std;

// constructor
LoadStore::LoadStore(IMemoryInterface *memory) : memory_interface(memory) {

}

uint64_t LoadStore::memory_buffer(uint16_t address, MemOperations op, uint16_t write_data) {
    return request_to_memory(address, op, write_data);
}

uint64_t LoadStore::request_to_memory(uint16_t address, MemOperations op, uint16_t write_data) {
    uint64_t result = 0;
    vector<uint16_t> words;

    switch (op) {
        case MemOperations::FETCH_64:
            words = memory_interface->readFetchWindow(address, 4);

            // punem cele 4 cuvinte intr un singur numar de 64 de biti
            for (size_t i = 0; i < words.size(); i++) {
                result |= (static_cast<uint64_t>(words[i]) << (i * 16));
            }
            break;

        case MemOperations::LOAD_16:
            result = memory_interface->read(address);
            break;

        case MemOperations::STORE_16:
            memory_interface->write(address, write_data);
            // doar scriem, nu returnam nimic relevant
            result = 0;
            break;
    }

    return receive_memory_data(result);
}


uint64_t LoadStore::receive_memory_data(uint64_t raw_data) {
    return raw_data;
}
