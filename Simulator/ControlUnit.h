#ifndef CONTROLUNIT_H_
#define CONTROLUNIT_H_

#include "Component.h"

class ControlUnit : public Component
{
public:
    ControlUnit();

    void fetch();
    void decode();

    //calls one of the four main steps given an opcode
    //jump, branch, exec, memcomp
    void invoke(); //TODO: change invoke to update it's own state

    void updateState();

    void jump();
    void branch();

    void exec();
    void rtype();
    
    void memcomp();
    void memaccess(); //used for lw/sw
    void memread();

    void print();

    typedef enum Inputs
    {
        Opcode

    } Inputs;

    typedef enum Outputs
    {
        PCWriteCond,
        PCWrite,
        IorD,
        MemRead,
        MemWrite,
        MemtoReg,
        IRWrite,
        PCSource,
        ALUOp,
        ALUSrcB,
        ALUSrcA,
        RegWrite,
        RegDst

    } Outputs;

    int state;

};

#endif /*CONTROLUNIT*/
