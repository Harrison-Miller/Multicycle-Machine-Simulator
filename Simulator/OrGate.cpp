#include "OrGate.h"

OrGate::OrGate() :
    Component(2, 1)
{
}

void OrGate::invoke()
{
    int a = inputs[A];
    int b = inputs[B];

    int q = a|b;
    
    put(Q, q);

}

void OrGate::print()
{
    int a = inputs[A];
    int b = inputs[B];

    std::cout << "A: " << a << " B: " << b << "\n";

    int q = *outputs[Q];

    std::cout << "Q: " << q << "\n";

}
