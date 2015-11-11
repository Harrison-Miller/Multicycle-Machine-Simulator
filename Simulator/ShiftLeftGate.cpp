#include "ShiftLeftGate.h"

ShiftLeftGate::ShiftLeftGate() :
    Component(1, 1)
{
}

void ShiftLeftGate::invoke()
{
    int in = inputs[In];
    in *= 4; //shifts the bits left 2

    put(Out, in);

}

void ShiftLeftGate::print()
{
    int in = inputs[In];
    std::cout << "in: " << in << " out: " << in*4 << "\n";

}
