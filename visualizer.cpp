#include <SFML/Graphics.hpp>
#include "Simulator/Machine.h"
#include "Graphs/Graphs.h"

int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(1024, 600), "multicycle machine visualizer", sf::Style::Close);
    window.setFramerateLimit(30);

    Machine machine;

    //simple adding
    /*machine.mmu.memory[0] = 0x20080003; //addi	$t0, $zero, 3
    machine.mmu.memory[1] = 0x21080005; //addi	$t0, $t0, 5
    machine.mmu.memory[2] = 0x20090004; //addi	$t1, $zero, 4
    machine.mmu.memory[3] = 0x21290002; //addi	$t1, $t1, 2
    machine.mmu.memory[4] = 0x01094022; //sub	$t0, $t0, $t1
    machine.mmu.memory[5] = 0x01008020; //add	$s0, $t0, $zero*/

    //branching program
    machine.mmu.memory[0] = 0x012a4820;
    machine.mmu.memory[1] = 0x21290001;
    machine.mmu.memory[2] = 0x214a0001;
    machine.mmu.memory[3] = 0x112afffc;


    sf::Font consolas;
    consolas.loadFromFile("consolas.ttf");

    RegisterGraph pc("PC", sf::Vector2f(50, 300), consolas, true, true);
    MultiplexerGraph iord(2, sf::Vector2f(100, 300), consolas);

    MemoryGraph mem(sf::Vector2f(150, 300), consolas);

    RegisterGraph memdata("Mem", sf::Vector2f(250, 400), consolas, false);

    MultiplexerGraph regdst(2, sf::Vector2f(375, 350), consolas);
    MultiplexerGraph memtoreg(2, sf::Vector2f(375, 400), consolas, false);

    RegisterFileGraph regs(sf::Vector2f(450, 300), consolas);

    RegisterGraph rega("A", sf::Vector2f(575, 300), consolas);
    RegisterGraph regb("B", sf::Vector2f(575, 350), consolas);

    ShiftLeftGateGraph immShift(sf::Vector2f(575, 450), consolas);
 
    MultiplexerGraph srca(2, sf::Vector2f(650, 300), consolas);
    MultiplexerGraph srcb(4, sf::Vector2f(650, 350), consolas, false);

    ALUGraph alu(sf::Vector2f(725, 275), consolas);

    ShiftLeftGateGraph jumpShift(sf::Vector2f(725, 200), consolas);

    RegisterGraph aluout("ALUOut", sf::Vector2f(850, 325), consolas, false);
    
    MultiplexerGraph pcsource(3, sf::Vector2f(950, 175), consolas);

    AndGateGraph pcwritecond(sf::Vector2f(300, 100), consolas);
    OrGateGraph pcwrite(sf::Vector2f(250, 125), consolas);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            pc.pollEvent(event);
            iord.pollEvent(event);
            mem.pollEvent(event);
            regdst.pollEvent(event);
            memtoreg.pollEvent(event);
            memdata.pollEvent(event);
            regs.pollEvent(event);
            rega.pollEvent(event);
            regb.pollEvent(event);
            immShift.pollEvent(event);
            srca.pollEvent(event);
            srcb.pollEvent(event);
            alu.pollEvent(event);
            jumpShift.pollEvent(event);
            aluout.pollEvent(event);
            pcsource.pollEvent(event);
            pcwritecond.pollEvent(event);
            pcwrite.pollEvent(event);

            if(event.type == sf::Event::Closed)
            {
                window.close();
                return 0;

            }
            else if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Space)
                {
                    machine.update();

                    pc.update(machine.PC);
                    iord.update(machine.IorD);
                    mem.update(machine.mmu);
                    memdata.update(machine.memData);
                    regdst.update(machine.RegDst);
                    memtoreg.update(machine.MemtoReg);
                    regs.update(machine.regs);
                    rega.update(machine.A);
                    regb.update(machine.B);
                    immShift.update(machine.immShift);
                    srca.update(machine.ALUSrcA);
                    srcb.update(machine.ALUSrcB);
                    alu.update(machine.alu);
                    jumpShift.update(machine.jumpShift);
                    aluout.update(machine.ALUOut);
                    pcsource.update(machine.PCSource);
                    pcwritecond.update(machine.PCWriteCond);
                    pcwrite.update(machine.PCWrite);

                }

            }

        }

        window.clear(sf::Color::White);

        pc.draw(window);
        iord.draw(window);
        mem.draw(window);
        memdata.draw(window);
        regdst.draw(window);
        memtoreg.draw(window);
        regs.draw(window);
        rega.draw(window);
        regb.draw(window);
        immShift.draw(window);
        srca.draw(window);
        srcb.draw(window);
        alu.draw(window);
        jumpShift.draw(window);
        aluout.draw(window);
        pcsource.draw(window);
        pcwritecond.draw(window);
        pcwrite.draw(window);

        window.display();

    }

    return 0;

}
