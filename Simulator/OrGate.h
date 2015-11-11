#ifndef ORGATE_H_
#define ORGATE_H_

#include "Component.h"

class OrGate : public Component
{
public:
    OrGate();

    void invoke();

    void print();

    typedef enum Inputs
    {
        A,
        B

    } Inputs;

    typedef enum Outputs
    {
        Q

    } Outputs;

};

#endif /*ORGATE*/
