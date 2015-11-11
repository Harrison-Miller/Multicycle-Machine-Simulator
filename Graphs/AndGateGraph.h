#ifndef ANDGATEGRAPH_H_
#define ANDGATEGRAPH_H_

#include "Graph.h"
#include "../Simulator/AndGate.h"

class AndGateGraph : public Graph<AndGate>
{
public:
    AndGateGraph(sf::Vector2f pos,
        sf::Font& consolas);

    void update(AndGate& gate);

    void updateBars();

    void draw(sf::RenderWindow& window,
        sf::RenderStates states = sf::RenderStates::Default);

    bool upOn;
    sf::RectangleShape upper;

    bool lowOn;
    sf::RectangleShape lower;

    int st;
    sf::RectangleShape shine;

};

#endif /*ANDGATEGRAPH*/
