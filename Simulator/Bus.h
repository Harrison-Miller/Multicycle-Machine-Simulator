#ifndef BUS_H_
#define BUS_H_

#include "Component.h"

class Bus : public Component
{
public:
    Bus();

    void invoke();

    void print();

    typedef enum Inputs
    {
        In

    } Inputs;

    typedef enum Outputs
    {
        O0,
        O1,
        O2,
        O3,
        O4,
        O5,
        O6,
        O7,
        O8,
        O9

    } Outpus;

};

#endif /*BUS*/
