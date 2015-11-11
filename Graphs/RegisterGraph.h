#ifndef REGISTERGRAPH_H_
#define REGISTERGRAPH_H_

#include "Graph.h"
#include "../Simulator/Register.h"

class RegisterGraph : public Graph<Register>
{
public:
    RegisterGraph(std::string name,
        sf::Vector2f pos,
        sf::Font& consolas,
        bool big = true,
        bool writebit = false);

    void update(Register& reg);

    void updateNum();

    void draw(sf::RenderWindow& window,
        sf::RenderStates states = sf::RenderStates::Default);

    sf::Text numText;

    int last;
    std::string nextValue;
    bool fadeOut;
    sf::Clock fadeTime;

};

#endif /*REGISTERGRAPH_H_*/
