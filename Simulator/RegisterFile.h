#ifndef REGISTERFILE_H_
#define REGISTERFILE_H_

#include "Component.h"

class RegisterFile : public Component
{
public:
    RegisterFile();

    void invoke();

    void print();

    typedef enum Inputs
    {
        ReadReg1,
        ReadReg2,
        WriteReg1,
        WriteData,
        RegWrite

    } Inputs;

    typedef enum Outputs
    {
        Data1,
        Data2

    } Outputs;

    std::vector<int> registers;

};

#endif /*REGISTERFILE*/
