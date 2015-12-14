#include "Machine.h"

Machine::Machine()
{
    //link up all the control signals
    cpu.link(PCWriteCond, AndGate::A, ControlUnit::PCWriteCond);
    cpu.link(PCWrite, OrGate::A, ControlUnit::PCWrite);
    cpu.link(IorD, Multiplexer::Sel, ControlUnit::IorD);
    cpu.link(mmu, MemoryUnit::MemRead, ControlUnit::MemRead);
    cpu.link(mmu, MemoryUnit::MemWrite, ControlUnit::MemWrite);
    cpu.link(MemtoReg, Multiplexer::Sel, ControlUnit::MemtoReg);
    cpu.link(ir, InstructionRegister::IRWrite, ControlUnit::IRWrite);
    cpu.link(PCSource, Multiplexer::Sel, ControlUnit::PCSource);
    cpu.link(aluControl, ALUControl::ALUOp, ControlUnit::ALUOp);
    cpu.link(ALUSrcB, Multiplexer::Sel, ControlUnit::ALUSrcB);
    cpu.link(ALUSrcA, Multiplexer::Sel, ControlUnit::ALUSrcA);
    cpu.link(regs, RegisterFile::RegWrite, ControlUnit::RegWrite);
    cpu.link(RegDst, Multiplexer::Sel, ControlUnit::RegDst);
    cpu.link(bnqcond, AndGate::A, ControlUnit::BNQWriteCond);
    cpu.link(RtisA, Multiplexer::Sel, ControlUnit::RtisA);

    //pc register write
    alu.link(zerobus, Bus::In, ArithmeticLogicUnit::Zero);
    zerobus.link(PCWriteCond, AndGate::B, Bus::O0);
    zerobus.link(notzero, NotGate::In, Bus::O1);
    notzero.link(bnqcond, AndGate::B, NotGate::Out);
    bnqcond.link(PCWriteF, OrGate::A, AndGate::Q);
    PCWrite.link(PCWriteF, OrGate::B, OrGate::Q);
    PCWriteF.link(PC, Register::Write, OrGate::Q);

    PCWriteCond.link(PCWrite, OrGate::B, AndGate::Q);
    PC.pc = true;
    PC.set(Register::Write, 0); //don't write initially

    //writing to pc
    PCSource.link(PC, Register::In, Multiplexer::Out);

    //pc to mux and bus
    PC.link(pcBus, Bus::In, Register::Out);
    pcBus.link(IorD, Multiplexer::I0, Bus::O0);
    pcBus.link(ALUSrcA, Multiplexer::I0, Bus::O1);
    pcBus.link(pcMask, AndGate::A, Bus::O2);

    //jump logic
    pcMask.set(AndGate::B, 0xf0000000);
    jumpShift.link(pcConcat, OrGate::A, ShiftLeftGate::Out);
    pcMask.link(pcConcat, OrGate::B, AndGate::Q);
    pcConcat.link(PCSource, Multiplexer::I2, OrGate::Q);

    //IorD mux
    IorD.link(mmu, MemoryUnit::Address, Multiplexer::Out);

    //mmu memdata and mmu bus
    mmu.link(mmuBus, Bus::In, MemoryUnit::MemData);
    mmuBus.link(ir, InstructionRegister::In, Bus::O0);
    mmuBus.link(memData, Register::In, Bus::O1);

    //instrution register and busses
    ir.link(RtisA, Multiplexer::I0, InstructionRegister::Rs);
    RtisA.link(regs, RegisterFile::ReadReg1, Multiplexer::Out);
    ir.link(rtBus, Bus::In, InstructionRegister::Rt);
    rtBus.link(regs, RegisterFile::ReadReg2, Bus::O0);
    rtBus.link(RegDst, Multiplexer::I0, Bus::O1);
    rtBus.link(RtisA, Multiplexer::I1, Bus::O2);
    ir.link(immBus, Bus::In, InstructionRegister::Imm);
    immBus.link(ALUSrcB, Multiplexer::I2, Bus::O0);
    immBus.link(immShift, ShiftLeftGate::In, Bus::O1);
    ir.link(functBus, Bus::In, InstructionRegister::Funct);
    functBus.link(aluControl, ALUControl::Funct, Bus::O0);
    functBus.link(cpu, ControlUnit::Func, InstructionRegister::Funct);
    ir.link(jumpShift, ShiftLeftGate::In, InstructionRegister::Address);
    ir.link(cpu, ControlUnit::Opcode, InstructionRegister::Opcode);
    ir.link(alu, ArithmeticLogicUnit::Shamt, InstructionRegister::Shamt);

    //register b and bus
    regs.link(B, Register::In, RegisterFile::Data2);
    B.link(BBus, Bus::In, Register::Out);
    BBus.link(ALUSrcB, Multiplexer::I0, Bus::O0);
    BBus.link(mmu, MemoryUnit::WriteData, Bus::O1);

    //register a
    regs.link(A, Register::In, RegisterFile::Data1);
    A.link(ALUSrcA, Multiplexer::I1, Register::Out);

    //alu src a
    ALUSrcA.link(alu, ArithmeticLogicUnit::A, Multiplexer::Out);

    //alu src b
    ALUSrcB.set(Multiplexer::I1, 4);
    ALUSrcB.set(Multiplexer::I4, 0);
    immShift.link(ALUSrcB, Multiplexer::I3, ShiftLeftGate::Out);
    ALUSrcB.link(alu, ArithmeticLogicUnit::B, Multiplexer::Out);

    //reg dst
    ir.link(RegDst, Multiplexer::I1, InstructionRegister::Rd);
    RegDst.set(Multiplexer::I2, 31); //ra
    RegDst.link(regs, RegisterFile::WriteReg1, Multiplexer::Out);

    //mem to reg
    memData.link(MemtoReg, Multiplexer::I1, Register::Out);
    MemtoReg.link(regs, RegisterFile::WriteData, Multiplexer::Out);

    //alu out and bus
    ALUOut.link(ALUOutBus, Bus::In, Register::Out);
    ALUOutBus.link(PCSource, Multiplexer::I1, Bus::O0);
    ALUOutBus.link(MemtoReg, Multiplexer::I0, Bus::O1);
    ALUOutBus.link(IorD, Multiplexer::I1, Bus::O2);

    //alu and alu ret bus
    alu.link(ALURet, Bus::In, ArithmeticLogicUnit::Y);
    ALURet.link(ALUOut, Register::In, Bus::O0);
    ALURet.link(PCSource, Multiplexer::I0, Bus::O1);

    //alucontrol
    aluControl.link(alu, ArithmeticLogicUnit::Opcode, ALUControl::Opcode);

}

void Machine::update()
{
    cpu.invoke(); //sets all the control signals and updates the state (cycle step)
    
    pcBus.invoke();

    IorD.invoke(); //chooses iord for fetching an address

    //reads or writes a value depending on the control signals set above
    mmu.invoke(); //sets the instruction value for the instruction register and stores the value in the memdata register
    mmuBus.invoke();

    ir.invoke(); //splits the instruction into it's component setting several mux values and shifts for other components
    rtBus.invoke();
    functBus.invoke();
    immBus.invoke();

    memData.invoke(); //updates the value used in the memtoreg mux

    RtisA.invoke();
    RegDst.invoke(); //chooses rt or rd for write register
    MemtoReg.invoke(); //chooses what is used for the data to be written

    //reads or writes values depending on control inputs
    regs.invoke(); //sets the value of registers a and b (outside reg file)

    //loads of registers and mux updates
    immShift.invoke();
    A.invoke();
    B.invoke();
    BBus.invoke();

    aluControl.invoke(); //given opcode, aluop decides a the alu operation

    ALUSrcA.invoke(); //decides a value for the alu
    ALUSrcB.invoke(); //decides b value for the alu

    alu.invoke(); //does math and stuff
    ALURet.invoke();

    //jump logic stuff
    jumpShift.invoke();
    pcMask.invoke();
    pcConcat.invoke();

    //updates pc value (doesn't actually do anything until pc is
    //invoked and checkes it's write value.. kinda hack but ohwell).
    PCSource.invoke();
    PCSource.print();

    ALUOut.invoke();
    ALUOutBus.invoke();
    
    zerobus.invoke();
    notzero.invoke();
    bnqcond.invoke();
    PCWriteCond.invoke();
    PCWrite.invoke();
    PCWriteF.invoke();

    PC.invoke(); //updates the mux with the current pc value

}

void Machine::print()
{
    std::cout << "\nControl Unit\n";
    cpu.print();

    std::cout << "\nPC\n";
    PC.print();

    std::cout << "\nIorD\n";
    IorD.print();

    std::cout << "\nMemory\n";
    mmu.print();

    std::cout << "\nInstructionRegister\n";
    ir.print();

    std::cout << "\nRegDst\n";
    RegDst.print();

    std::cout << "\nMemtoReg\n";
    MemtoReg.print();

    std::cout << "\nRegisters\n";
    regs.print();

    std::cout << "\nALUControl\n";
    aluControl.print();

    std::cout << "\nALUSrcA\n";
    ALUSrcA.print();

    std::cout << "\nImmediate\n";
    immBus.print();

    std::cout << "\nALUSrcB\n";
    ALUSrcB.print();

    std::cout << "\nALU\n";
    alu.print();

    std::cout << "\nPCSource\n";
    PCSource.print();

    std::cout << "\nJumpShift\n";
    jumpShift.print();

}
