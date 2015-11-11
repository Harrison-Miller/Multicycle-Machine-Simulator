#include "Bus.h"

Bus::Bus() :
    Component(1, 10)
{
}

void Bus::invoke()
{
    int in = inputs[In];

    put(O0, in);
    put(O1, in);
    put(O2, in);
    put(O3, in);
    put(O4, in);
    put(O5, in);
    put(O6, in);
    put(O7, in);
    put(O8, in);
    put(O9, in);

}

void Bus::print()
{
    int in = inputs[In];

    std::cout << "value: " << in << "\n";

}
