#include "ArithmeticLogicUnit.h"

ArithmeticLogicUnit::ArithmeticLogicUnit() :
    Component(3, 2)
{
}

void ArithmeticLogicUnit::invoke()
{
    //TODO: do stuff with that status input/output

    int op = inputs[Opcode];

    int a = inputs[A];
    int b = inputs[B];

    int y = 0;

    if(op == And)
    {
        y = a&b;

    }
    else if(op == Or)
    {
        y = a|b;

    }
    else if(op == Add)
    {
        y = a + b;

    }
    else if(op == Sub)
    {
        y = a - b;

    }
    else if(op == Slt)
    {
        y = a < b ? 1 : 0;

    }

    put(Y, y);
    put(Zero, y == 0 ? 1 : 0);

}

void ArithmeticLogicUnit::print()
{
    int op = inputs[Opcode];

    int a = inputs[A];
    int b = inputs[B];

    std::cout << "A: " << a << " B: " << b << "\n";
    if(op == And)
    {
        std::cout << "Op: and\n";

    }
    else if(op == Or)
    {
        std::cout << "Op: or\n";

    }
    else if(op == Add)
    {
        std::cout << "Op: add\n";

    }
    else if(op == Sub)
    {
        std::cout << "Op: sub\n";

    }
    else if(op == Slt)
    {
        std::cout << "Op: slt\n";

    }

    int y = *outputs[Y];
    std::cout << "Y: " << y << "\n";

}
