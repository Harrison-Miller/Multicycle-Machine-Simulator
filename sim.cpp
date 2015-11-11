#include "Simulator/Machine.h"
#include "Graphs/Graphs.h"

int main(int argc, char** argv)
{
    Machine machine;

    //can't use immeadiate since I don't have that so loading up the registers
    /*machine.regs.registers[16] = 3;
    machine.regs.registers[17] = 5;
    machine.regs.registers[18] = 4;
    machine.regs.registers[19] = 2;*/

    machine.mmu.memory[0] = 0x20080003; //add	$t0, $zero, 3
    machine.mmu.memory[1] = 0x21080005; //add	$t0, $t0, 5
    machine.mmu.memory[2] = 0x20090004; //add	$t1, $zero, 4
    machine.mmu.memory[3] = 0x21290002; //add	$t1, $t1, 2
    machine.mmu.memory[4] = 0x01094022; //sub	$t0, $t0, $t1
    machine.mmu.memory[5] = 0x01008020; //add	$s0, $t0, $zero

    for(int i = 0; i < 6; i++)
    {
        while(machine.cpu.state != 0)
        {
            std::cout << "\n//////////\nSTATE: " << machine.cpu.state << "\n//////////\n";
            machine.update();
            machine.print();

        }

        std::cout << "\n//////////\nSTATE: " << machine.cpu.state << "\n//////////\n";
        machine.update();
        machine.print();

    }

    return 0;

}
