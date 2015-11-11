#ifndef ANDGATE_H_
#define ANDGATE_H_

#include "Component.h"

class AndGate : public Component
{
public:
    AndGate();

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

#endif /*ANDGATE*/
