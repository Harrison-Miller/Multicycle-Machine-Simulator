#include "ControlUnit.h"

ControlUnit::ControlUnit() :
    Component(1, 13),
    state(0)
{
}

void ControlUnit::fetch()
{
    put(MemRead, 1);
    put(MemWrite, 0);
    put(ALUSrcA, 0);
    put(IorD, 0);
    put(IRWrite, 1);
    put(ALUSrcB, 1);
    put(ALUOp, 0);
    put(PCWrite, 1);
    put(PCSource, 0);
    put(PCWriteCond, 0);
    put(RegWrite, 0);

}

void ControlUnit::decode()
{
    //turn these off
    put(MemRead, 0);
    put(IRWrite, 0);
    put(PCWrite, 0);

    put(ALUSrcA, 0);
    put(ALUSrcB, 3);
    put(ALUOp, 0);

}

void ControlUnit::invoke()
{
    if(state == 0)
    {
        fetch();

    }
    else if(state == 1)
    {
        decode();

    }
    else if(state == 2)
    {
        memcomp();

    }
    else if(state == 3 || state == 5)
    {
        memaccess();

    }
    else if(state == 4)
    {
        memread();

    }
    else if(state == 6)
    {
        exec();

    }
    else if(state == 7)
    {
        rtype();

    }
    else if(state == 8)
    {
        branch();

    }
    else if(state == 9)
    {
        jump();

    }

    updateState();

}

void ControlUnit::updateState()
{
    int op = inputs[Opcode];

    if(state == 0 || state == 6 || state == 3)
    {
        state++;

    }
    else if(state == 4 || state == 5 || state == 7 || state == 8 || state == 9)
    {
        state = 0;

    }
    else if(state == 1)
    {
        if(op == 0x2) //j, jal || op == 0x3
        {
            state = 9;
            
        }
        else if(op == 0x4) //beq, bne || op == 0x5
        {
            state = 8;

        }
        else if(op == 0x0) //r-type functions
        {
            state = 6;

        }
        else if(op == 0x23 || op == 0x2b) //lw, sw
        {
            state = 2;

        }
        else
        {
            state = 6;

        }

    }
    else if(state == 2)
    {
        if(op == 0x23) //lw
        {
            state = 3;

        }
        else if(op == 0x2b) //sw
        {
            state = 5;

        }

    }

}

void ControlUnit::jump()
{
    put(PCWrite, 1);
    put(PCSource, 2);

}

void ControlUnit::branch()
{
    put(ALUSrcA, 1);
    put(ALUSrcB, 0);
    put(ALUOp, 1);
    put(PCWriteCond, 1);
    put(PCSource, 1);

}

void ControlUnit::exec()
{
    put(ALUSrcA, 1);

    int op = inputs[Opcode];
    if(op == 0x0)
    {
        put(ALUSrcB, 0);
        put(ALUOp, 2);

    }
    else 
    {
        put(ALUSrcB, 2);
        put(ALUOp, op);

    }


}

void ControlUnit::rtype()
{
    int op = inputs[Opcode];
    if(op == 0x0)
    {
        put(RegDst, 1);

    }
    else
    {
        put(RegDst, 0);

    }

    put(RegWrite, 1);
    put(MemtoReg, 0);

}

void ControlUnit::memcomp()
{
    put(ALUSrcA, 1);
    put(ALUSrcB, 2);
    put(ALUOp, 0);

}

void ControlUnit::memaccess()
{
    int op = inputs[Opcode];
    put(IorD, 1);

    if(op == 0x23) //lw
    {
        put(MemRead, 1);

    }
    else if(op == 0x2b) //sw
    {
        put(MemWrite, 1);

    }

}

void ControlUnit::memread()
{
    put(MemRead, 0);
    put(RegDst, 0);
    put(RegWrite, 1);
    put(MemtoReg, 1);

}

void ControlUnit::print()
{
    std::cout << "PCWriteCond: " << *outputs[PCWriteCond] << "\n";
    std::cout << "PCWrite: " << *outputs[PCWrite] << "\n";
    std::cout << "IorD: " << *outputs[IorD] << "\n";
    std::cout << "MemRead: " << *outputs[MemRead] << "\n";
    std::cout << "MemWrite: " << *outputs[MemWrite] << "\n";
    std::cout << "IRWrite: " << *outputs[IRWrite] << "\n";
    std::cout << "PCSource: " << *outputs[PCSource] << "\n";
    std::cout << "ALUOp: " << *outputs[ALUOp] << "\n";
    std::cout << "ALUSrcA: " << *outputs[ALUSrcA] << "\n";
    std::cout << "ALUSrcB: " << *outputs[ALUSrcB] << "\n";
    std::cout << "RegWrite: " << *outputs[RegWrite] << "\n";
    std::cout << "RegDst: " << *outputs[RegDst] << "\n";

}
