#ifndef ARITHMETICLOGICUNIT_H_
#define ARITHMETICLOGICUNIT_H_

#include "Component.h"

class ArithmeticLogicUnit : public Component
{
public:
    ArithmeticLogicUnit();

    void invoke();

    void print();

    typedef enum Inputs
    {
        A,
        B,
        Opcode,
        Shamt

    } Inputs;

    typedef enum Outputs
    {
        Y,
        Zero

    } Outputs;

    typedef enum Code
    {
        And = 0,
        Or = 1,
        Add = 2,
        Sub = 6,
        Slt = 7,
        Nor = 8,
        Sll = 9,
        Slr = 10

    } Code;

};

#endif /*ARITHMETICLOGICUNIT*/
