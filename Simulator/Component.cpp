#include "Component.h"

Component::Component(int inputsCount,
    int outputsCount)
{
    for(int i = 0; i < inputsCount; i++)
    {
        inputs.push_back(0);

    }

    for(int i = 0; i < outputsCount; i++)
    {
        outputs.push_back(NULL);

    }

}

void Component::link(Component& component,
    int input,
    int output)
{
    outputs[output] = &component.inputs[input];

}

void Component::unlink(int output)
{
    outputs[output] = NULL;

}

void Component::set(int i,
    int a)
{
    inputs[i] = a;

}

void Component::put(int output,
    int a)
{
    int* ptr = outputs[output];
    if(ptr != NULL)
    {
        *ptr = a;

    }

}
