#ifndef CISC_INSTRUCTION_SET_SIMULATOR_INTERFACES_H
#define CISC_INSTRUCTION_SET_SIMULATOR_INTERFACES_H

// interfata catre memoria externa (folosita de LoadStore)
class IMemoryInterface {
public:
    // virtual destructor
    virtual ~IMemoryInterface()= default;
    virtual void AccessMemory() = 0;
};

// interfata catre Load/Store (folosita de Fetch & Execute)
class ILoadStoreInterface {
    virtual ~ILoadStoreInterface() = default;
    virtual void memory_buffer() = 0;
};

// interfata catre Decode (folosita de Fetch)
class IDecodeInterface {
    virtual ~IDecodeInterface() = default;
    virtual void decode_instruction() = 0;
};

#endif //CISC_INSTRUCTION_SET_SIMULATOR_INTERFACES_H
