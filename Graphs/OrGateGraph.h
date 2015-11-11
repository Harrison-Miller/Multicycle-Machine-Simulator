#ifndef ORGATEGRAPH_H_
#define ORGATEGRAPH_H_

#include "Graph.h"
#include "../Simulator/OrGate.h"

class OrGateGraph : public Graph<OrGate>
{
public:
    OrGateGraph(sf::Vector2f pos,
        sf::Font& consolas);

    void update(OrGate& gate);

    void updateBars();

    void draw(sf::RenderWindow& window,
        sf::RenderStates states = sf::RenderStates::Default);

    bool upOn;
    bool lowOn;
    sf::RectangleShape bar;

    int st;
    sf::RectangleShape shine;

};

#endif /*ORGATEGRAPH*/
