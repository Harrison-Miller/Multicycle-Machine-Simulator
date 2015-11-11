#include "Multiplexer.h"

Multiplexer::Multiplexer() :
    Component(11, 1)
{
}

void Multiplexer::invoke()
{
    int sel = inputs[Sel]+1;
    int a = inputs[sel];
    put(Out, a);

}

void Multiplexer::print()
{
    int sel = inputs[Sel];
    std::cout << "Sel: " << sel << "\n";

    std::cout << "Out: " << inputs[sel+1] << "\n";

}
