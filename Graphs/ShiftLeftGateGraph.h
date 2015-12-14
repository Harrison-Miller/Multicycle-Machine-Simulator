#ifndef SHIFTLEFTGATEGRAPH_H_
#define SHIFTLEFTGATEGRAPH_H_

#include "Graph.h"
#include "../Simulator/ShiftLeftGate.h"

class ShiftLeftGateGraph : public Graph<ShiftLeftGate>
{
public:
    ShiftLeftGateGraph(sf::Vector2f pos,
        sf::Font& consolas);

    void update(ShiftLeftGate& sll);

    void draw(sf::RenderWindow& window,
        sf::RenderStates states = sf::RenderStates::Default);

    sf::CircleShape base;

};

#endif /*SHIFTLEFTGATEGRAPH*/
