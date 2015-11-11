#include "ALUControl.h"
#include "ArithmeticLogicUnit.h"

ALUControl::ALUControl() :
    Component(2, 1)
{
}

void ALUControl::invoke()
{
    int op = inputs[ALUOp];
    int funct = inputs[Funct];

    if(op == LSWord)
    {
        put(Opcode, ArithmeticLogicUnit::Add);
        
    }
    else if(op == Beq)
    {
        put(Opcode, ArithmeticLogicUnit::Sub);

    }
    else if(op == Arithmetic)
    {
        int masked = funct&0xf;
        if(masked == Add || op == 0x8)
        {
            put(Opcode, ArithmeticLogicUnit::Add);

        }
        else if(masked == Sub)
        {
            put(Opcode, ArithmeticLogicUnit::Sub);

        }
        else if(masked == And || op == 0xc)
        {
            put(Opcode, ArithmeticLogicUnit::And);

        }
        else if(masked == Or || op == 0xd)
        {
            put(Opcode, ArithmeticLogicUnit::Or);

        }
        else if(masked == Slt)
        {
            put(Opcode, ArithmeticLogicUnit::Slt);

        }

    }

}

void ALUControl::print()
{
    int op = inputs[ALUOp];
    int funct = inputs[Funct];

    std::cout << "Op: " << op << "\n";
    std::cout << "Funct: " << funct << "\n";

}
