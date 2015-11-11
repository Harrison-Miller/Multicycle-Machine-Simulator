#ifndef SHIFTLEFTGATE_H_
#define SHIFTLEFTGATE_H_

#include "Components.h"

class ShiftLeftGate : public Component
{
public:
    ShiftLeftGate();

    void invoke();

    void print();

    typedef enum Inputs
    {
        In

    } Inputs;

    typedef enum Outputs
    {
        Out

    } Output;

};

#endif /*SHIFTLEFTGATE*/
