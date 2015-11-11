#include "InstructionRegister.h"

InstructionRegister::InstructionRegister() :
    Component(2, 8),
    stored(0)
{
}

void InstructionRegister::invoke()
{
    int in = inputs[In];

    int w = inputs[IRWrite];
    if(w)
    {
        stored = in;

    }

    int op =        stored&0b11111100000000000000000000000000;
    op = op >> 26;

    int rs =        stored&0b00000011111000000000000000000000;
    rs = rs >> 21;

    int rt =        stored&0b00000000000111110000000000000000;
    rt = rt >> 16;
    
    int rd =        stored&0b00000000000000001111100000000000;
    rd = rd >> 11;

    int shamt =     stored&0b00000000000000000000011111000000;
    shamt = shamt >> 6;

    int funct =     stored&0b00000000000000000000000000111111;

    int imm =       stored&0b00000000000000001111111111111111;

    int address =   stored&0b00000011111111111111111111111111;

    //mask bits out to get the individual values of the instruction
    put(Opcode, op);
    put(Rs, rs);
    put(Rt, rt);
    put(Rd, rd);
    put(Shamt, shamt);
    put(Funct, funct);
    put(Imm, imm);
    put(Address, address);

}

void InstructionRegister::print()
{
    int in = inputs[In];
    std::cout << "Instruction: " << in << "\n";

}
