#include "AndGate.h"

AndGate::AndGate() :
    Component(2, 1)
{
}

void AndGate::invoke()
{
    int a = inputs[A];
    int b = inputs[B];

    int q = a&b;
    
    put(Q, q);

}

void AndGate::print()
{
    int a = inputs[A];
    int b = inputs[B];

    std::cout << "A: " << a << " B: " << b << "\n";

    int q = *outputs[Q];

    std::cout << "Q: " << q << "\n";

}
