#ifndef CISC_INSTRUCTION_SET_SIMULATOR_INTERFACES_H
#define CISC_INSTRUCTION_SET_SIMULATOR_INTERFACES_H

#include <cstdint>
#include <vector>

using namespace std;

// tipurile de operatii pe care le poate cere CPU-ul
enum class MemOperations {
    FETCH_64, // pentru fetch
    LOAD_16,  // pentru Execute (citire date)
    STORE_16  // pentru Execute (scriere date)
};

// interfata catre memoria externa (folosita de LoadStore)
class IMemoryInterface {
public:
    // virtual destructor
    virtual ~IMemoryInterface()= default;

    virtual vector<uint16_t> readFetchWindow(uint16_t address, int count) = 0;
    virtual uint16_t read(uint16_t address) = 0;
    virtual bool write(uint16_t address, uint16_t value) = 0;
};

// interfata catre Load/Store (folosita de Fetch & Execute)
class ILoadStoreInterface {
public:
    virtual ~ILoadStoreInterface() = default;

    // primeste o adresa, tipul operatiei si datele de scris daca este cazul si returneaza 64 de biti
    virtual uint64_t memory_buffer(uint16_t address, MemOperations op, uint16_t write_data) = 0;
};

// interfata catre Decode (folosita de Fetch)
class IDecodeInterface {
public:
    virtual ~IDecodeInterface() = default;

    // primeste fetch window-ul de 64 de biti de la Fetch
    virtual void decode_instruction(uint64_t fetch_window) = 0;
};

class IExecuteInterface {
public:
    virtual ~IExecuteInterface() = default;
    virtual void execute_instruction() = 0;
};
#endif //CISC_INSTRUCTION_SET_SIMULATOR_INTERFACES_H
