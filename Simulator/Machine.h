#ifndef MACHINE_H_
#define MACHINE_H_

#include "Components.h"

class Machine
{
public:
    Machine();

    void update();

    void print();

    ControlUnit cpu;

    AndGate PCWriteCond;
    OrGate PCWrite;

    MemoryUnit mmu;
    Bus mmuBus;

    InstructionRegister ir;
    Bus rtBus;
    Bus immBus;

    RegisterFile regs;

    ArithmeticLogicUnit alu;
    Bus ALURet;

    ALUControl aluControl;

    Multiplexer IorD;
    Multiplexer RegDst;
    Multiplexer MemtoReg;
    Multiplexer ALUSrcA;
    Multiplexer ALUSrcB;
    Multiplexer PCSource;

    Register PC;
    Bus pcBus;
    AndGate pcMask;
    AndGate pcConcat;

    Register memData;
    Register A;

    Register B;
    Bus BBus;

    Register ALUOut;
    Bus ALUOutBus;

    ShiftLeftGate immShift;
    ShiftLeftGate jumpShift;

};

#endif /*MACHINE*/
