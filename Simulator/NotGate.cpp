#include "NotGate.h"

NotGate::NotGate() :
    Component(1, 1)
{
}

void NotGate::invoke()
{
    int in = inputs[In];

    int out = !in;
    
    put(Out, out);

}

void NotGate::print()
{
}
