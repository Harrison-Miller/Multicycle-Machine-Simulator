#include "ShiftLeftGateGraph.h"

ShiftLeftGateGraph::ShiftLeftGateGraph(sf::Vector2f pos,
    sf::Font& consolas) :
    Graph(pos, consolas, "<<", sf::Vector2f(10, 10))
{
    base.setRadius(20);
    base.setOrigin(20, 20);
    base.setOutlineColor(sf::Color::Black);
    base.setOutlineThickness(1.0f);

    addPort(sf::Vector2f(-20, 0), "In", consolas, true);
    addPort(sf::Vector2f(20, 0), "Out", consolas, false);

}

void ShiftLeftGateGraph::update(ShiftLeftGate& sll)
{
}

void ShiftLeftGateGraph::draw(sf::RenderWindow& window,
    sf::RenderStates states)
{
    states.transform *= getTransform();

    for(int i = 0; i < ports.size(); i++)
    {
        window.draw(ports[i], states);
        if(isleft[i])
        {
            hover[i].setPosition(ports[i].getPosition());
            hover[i].move(-(hover[i].getLocalBounds().width + 8), 0);

        }
        window.draw(hover[i], states);

    }

    window.draw(base, states);
    window.draw(title, states);

}
