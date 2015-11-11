#include "MemoryUnit.h"

MemoryUnit::MemoryUnit() :
    Component(4, 1)
{
    for(int i = 0; i < 1000000; i++)
    {
        memory.push_back(0);

    }

}

void MemoryUnit::invoke()
{
    int mr = inputs[MemRead];
    int mw = inputs[MemWrite];

    int address = inputs[Address];
    int data = inputs[WriteData];

    if(mr)
    {
        address /= 4;
        int md = memory[address];
        put(MemData, md);

    }

    if(mw)
    {
        memory[address] = data;

    }

}

void MemoryUnit::print()
{
    int mr = inputs[MemRead];
    int mw = inputs[MemWrite];

    int address = inputs[Address];
    int data = inputs[WriteData];

    std::cout << "Address: " << address << "\n";
    std::cout << "MemRead: " << mr << " MemWrite: " << mw << "\n";

    if(mr)
    {
        address /= 4; //so it's alligned for our memory
        std::cout << "Data: " << memory[address] << "\n";

    }

    if(mw)
    {
        std::cout << "Data: " << data << "\n";

    }

}
