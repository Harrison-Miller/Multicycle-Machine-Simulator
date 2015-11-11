#ifndef MEMORYUNIT_H_
#define MEMORYUNIT_H_

#include "Component.h"

class MemoryUnit : public Component
{
public:
    MemoryUnit();

    void invoke();

    void print();

    typedef enum Inputs
    {
        Address,
        WriteData,
        MemRead,
        MemWrite

    } Inputs;

    typedef enum Outputs
    {
        MemData

    } Outputs;

    std::vector<int> memory;

};

#endif /*MEMORYUNIT*/
