#ifndef REGISTER_H_
#define REGISTER_H_

#include "Component.h"

class Register : public Component
{
public:
    Register(int a = 0); //default value of the register
    
    void invoke();

    void print();

    typedef enum Inputs
    {
        In,
        Write

    } Inputs;

    typedef enum Outputs
    {
        Out

    } Outputs;

    int stored;

};

#endif /*REGISTER*/
