#ifndef NOTGATE_H_
#define NOTGATE_H_

#include "Component.h"

class NotGate : public Component
{
public:
    NotGate();

    void invoke();

    void print();

    typedef enum Inputs
    {
        In

    } Inputs;

    typedef enum Outputs
    {
        Out

    } Outputs;

};

#endif /*NOTGATE*/
