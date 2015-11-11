#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <vector>
#include <iostream>

class Component
{
public:
    //intializes inputs/outputs
    //inputs = 0
    //outputs = NULL
    Component(int inputsCount,
        int outputsCount);

    //links an output from this component to an input of another
    void link(Component& component, //component to link to
        int input, //input from the other component
        int output); //output we want to link to the input

    //sets an output to NULL
    void unlink(int output);

    //sets the value of an input
    void set(int i, //input to set
        int a); //value of the input

    //sets the value of an output
    void put(int out, //output to set
        int a); //value to set it to

    //should perform logic given the inputs and use put
    //to set the outputs
    virtual void invoke() = 0;

    virtual void print() = 0;

    std::vector<int> inputs;
    std::vector<int*> outputs;

};

#endif /*COMPONENT*/
