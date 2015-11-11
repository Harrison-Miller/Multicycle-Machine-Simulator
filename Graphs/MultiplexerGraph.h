#ifndef MULTIPLEXERGRAPH_H_
#define MULTIPLEXERGRAPH_H_

#include "Graph.h"
#include "../Simulator/Multiplexer.h"

class MultiplexerGraph : public Graph<Multiplexer>
{
public:
    MultiplexerGraph(int inputs,
        sf::Vector2f pos,
        sf::Font& consolas,
        bool seltop = true);

    void update(Multiplexer& mux);

    void draw(sf::RenderWindow& window,
        sf::RenderStates states = sf::RenderStates::Default);

    int inputs;

    sf::VertexArray active;

    std::vector<sf::VertexArray> wires;
    int last;

};

#endif /*MULTIPLEXERGRAPH*/
