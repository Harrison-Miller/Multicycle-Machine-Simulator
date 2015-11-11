#ifndef ALUCONTROL_H_
#define ALUCONTROL_H_

#include "Component.h"

class ALUControl : public Component
{
public:
    ALUControl();

    void invoke();

    void print();

    typedef enum Inputs
    {
        Funct,
        ALUOp

    } Inputs;

    typedef enum Outputs
    {
        Opcode

    } Outputs;

    typedef enum OpType
    {
        LSWord,
        Beq,
        Arithmetic,
    

    } OpType;

    typedef enum FunctCode
    {
        Add = 0,
        Sub = 2,
        And = 4,
        Or = 5,
        Slt = 10

    } FunctCode;

};

#endif /*ALUCONTROL*/
