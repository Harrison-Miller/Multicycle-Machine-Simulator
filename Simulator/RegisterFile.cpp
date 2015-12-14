#include "RegisterFile.h"

RegisterFile::RegisterFile() :
    Component(5, 2)
{
    for(int i = 0; i < 32; i++)
    {
        registers.push_back(0);

    }

    registers[29] = 2147479548;

}

void RegisterFile::invoke()
{
    int r1 = inputs[ReadReg1];
    int r2 = inputs[ReadReg2];

    int d1 = registers[r1];
    int d2 = registers[r2];

    put(Data1, d1);
    put(Data2, d2);

    int w1 = inputs[WriteReg1];
    int data = inputs[WriteData];

    int rw = inputs[RegWrite];

    if(rw)
    {
        registers[w1] = data;

    }

}

void RegisterFile::print()
{
    int rw = inputs[RegWrite];

    if(rw)
    {
        int w1 = inputs[WriteReg1];

        std::cout << "WriteReg1: " << w1 << " = " << registers[w1] << "\n";


    }
    else
    {
        int r1 = inputs[ReadReg1];
        int r2 = inputs[ReadReg2];

        std::cout << "ReadReg1: " << r1 << " = " << registers[r1] << "\n";
        std::cout << "ReadReg2: " << r2 << " = " << registers[r2] << "\n";

    }

}

void RegisterFile::printContents()
{
    std::cout << "REGISTER FILE\n";
    for(int i = 0; i < 32; i++)
    {
        std::cout << i << "\t" << registers[i] << "\n";

    }

}
