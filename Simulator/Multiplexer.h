#ifndef MULTIPLEXER_H_
#define MULTIPLEXER_H_

#include "Component.h"

class Multiplexer : public Component
{
public:
    //multiplexer defaults to input 0
    Multiplexer();

    void invoke();

    void print();

    typedef enum Inputs
    {
        Sel,
        I0,
        I1,
        I2,
        I3,
        I4,
        I5,
        I6,
        I7,
        I8,
        I9

    } Inputs;

    typedef enum Outputs
    {
        Out

    } Outputs;

};

#endif /*MULTIPLEXER*/
