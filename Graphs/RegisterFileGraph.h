#ifndef REGISTERFILEGRAPH_H_
#define REGISTERFILEGRAPH_H_

#include "Graph.h"
#include "../Simulator/RegisterFile.h"

class RegisterFileGraph : public Graph<RegisterFile>
{
public:
    RegisterFileGraph(sf::Vector2f pos,
        sf::Font& consolas);

    void pollEvent(sf::Event& event);

    void reposition();

    void update(RegisterFile& regs);

    void draw(sf::RenderWindow& window,
        sf::RenderStates states = sf::RenderStates::Default);

    int top;

    std::vector<sf::Text> names;
    std::vector<sf::Text> values;

    sf::CircleShape upTri;
    sf::CircleShape downTri;

};

#endif /*REGISTERFILEGRAPH*/
