#ifndef INSTRUCTIONREGISTER_H_
#define INSTRUCTIONREGISTER_H_

#include "Component.h"

class InstructionRegister : public Component
{
public:
    InstructionRegister();

    void invoke();

    void print();

    typedef enum Inputs
    {
        In,
        IRWrite

    } Inputs;

    typedef enum Outputs
    {
        Opcode,
        Rs,
        Rt,
        Rd,
        Shamt,
        Funct,
        Imm,
        Address

    } Outputs;

private:
    int stored;

};

#endif /*INSTRUCTIONREGISTER*/
