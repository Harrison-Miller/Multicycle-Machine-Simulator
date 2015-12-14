#ifndef ALUGRAPH_H_
#define ALUGRAPH_H_

#include "Graph.h"
#include "../Simulator/ArithmeticLogicUnit.h"

class ALUGraph : public Graph<ArithmeticLogicUnit>
{
public:
    ALUGraph(sf::Vector2f pos,
        sf::Font& consolas);

    void update(ArithmeticLogicUnit& alu);

    void draw(sf::RenderWindow& window,
        sf::RenderStates states = sf::RenderStates::Default);

    sf::VertexArray points;

};

#endif /*ALUGRAPH*/
