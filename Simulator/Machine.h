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

    Bus zerobus;

    AndGate PCWriteCond;
    OrGate PCWrite;
    OrGate PCWriteF;
    NotGate notzero;
    AndGate bnqcond;

    MemoryUnit mmu;
    Bus mmuBus;

    InstructionRegister ir;
    Bus functBus;
    Bus rtBus;
    Bus immBus;


    RegisterFile regs;

    ArithmeticLogicUnit alu;
    Bus ALURet;

    ALUControl aluControl;

    Multiplexer IorD;
    Multiplexer RtisA;
    Multiplexer RegDst;
    Multiplexer MemtoReg;
    Multiplexer ALUSrcA;
    Multiplexer ALUSrcB;
    Multiplexer PCSource;

    Register PC;
    Bus pcBus;
    AndGate pcMask;
    OrGate pcConcat;

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
