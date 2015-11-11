#ifndef MEMORYGRAPH_H_
#define MEMORYGRAPH_H_

#include "Graph.h"
#include "../Simulator/MemoryUnit.h"

class MemoryGraph : public Graph<MemoryUnit>
{
public:
    MemoryGraph(sf::Vector2f pos,
        sf::Font& consolas);

    void update(MemoryUnit& mem);

    void draw(sf::RenderWindow& window,
        sf::RenderStates states = sf::RenderStates::Default);

};

#endif /*MEMORYGRAPH*/
