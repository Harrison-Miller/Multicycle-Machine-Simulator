#include "Simulator/Machine.h"
#include "Graphs/Graphs.h"
#include <fstream>
#include <sstream>

int hexStrToInt(std::string str)
{
    std::stringstream ss;
    ss << std::hex << str;
    int i = 0;
    ss >> i;
    return i;

}

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        std::cout << "usage: ./sim <filename>\n";
        return 0;

    }

    std::string filename = argv[1];

    std::fstream f;
    f.open(filename.c_str());
    if(!f)
    {
        std::cout << "failed to open: " << filename << "\n";

    }

    Machine machine;

    std::string line;

    bool first = true;

    while(std::getline(f, line))
    {
        int addr = 0;
        int instr = 0;
        if(first)
        {
            int start = hexStrToInt(line);
            machine.PC.stored = start;
            std::cout << "start: " << start << "\n";
            first = false;
            continue;

        }

        if(line.find(" ") != std::string::npos)
        {
            addr = hexStrToInt(line.substr(0, line.find(" ")));
            instr = hexStrToInt(line.substr(line.find(" ")+1));

        }
        else if(line.find("\t") != std::string::npos)
        {
            addr = hexStrToInt(line.substr(0, line.find("\t")));
            instr = hexStrToInt(line.substr(line.find("\t")+1));

        }

        if(addr == 0 && instr == 0)
        {
            break;

        }

        addr /= 4;

        machine.mmu.memory[addr] = instr;

    }

    machine.PC.invoke();

    
    int i = 0;
    while(machine.cpu.state != 1 || (machine.cpu.state == 1 && machine.mmu.memory[machine.PC.stored/4] != 0))
    {
        while(machine.cpu.state != 0)
        {
            std::cout << "\n//////////\nSTATE: " << machine.cpu.state << "\n//////////\n";
            machine.update();
            machine.print();

        }

        i++;
        std::cout << "\n//////////\nSTATE: " << machine.cpu.state << "\n//////////\n";
        machine.update();
        machine.print();

    }

    while(machine.cpu.state != 0)
    {
        std::cout << "\n//////////\nSTATE: " << machine.cpu.state << "\n//////////\n";
        machine.update();
        machine.print();

    }


    machine.regs.printContents();

    return 0;

}
