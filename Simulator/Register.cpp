#include "Register.h"

Register::Register(int a) :
    Component(2, 1),
    stored(0)
{
    set(In, a);
    set(Write, 1);

}

void Register::invoke()
{
    int a = inputs[In];
    int w = inputs[Write];

    if(w)
    {
        stored = a;

    }

    put(Out, stored);

}

void Register::print()
{
    //cheaty but whatever
    int a = inputs[In];
    int w = inputs[Write];

    if(w)
    {
        stored = a;

    }

    std::cout << "value: " << stored << "\n";

}
