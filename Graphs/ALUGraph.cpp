#include "ALUGraph.h"

ALUGraph::ALUGraph(sf::Vector2f pos,
    sf::Font& consolas) :
    Graph(pos, consolas, "ALU", sf::Vector2f(30, 30))
{
    points = sf::VertexArray(sf::LinesStrip, 8);
    points[0] = sf::Vertex(sf::Vector2f(0, 0), sf::Color::Black);
    points[1] = sf::Vertex(sf::Vector2f(75, 45), sf::Color::Black);
    points[2] = sf::Vertex(sf::Vector2f(75, 120), sf::Color::Black);
    points[3] = sf::Vertex(sf::Vector2f(0, 165), sf::Color::Black);
    points[4] = sf::Vertex(sf::Vector2f(0, 105), sf::Color::Black);
    points[5] = sf::Vertex(sf::Vector2f(21, 84), sf::Color::Black);
    points[6] = sf::Vertex(sf::Vector2f(0, 63), sf::Color::Black);
    points[7] = sf::Vertex(sf::Vector2f(0, 0), sf::Color::Black);

    addPort(sf::Vector2f(0, 30), "A", consolas, true);
    addPort(sf::Vector2f(0, 135), "B", consolas, true);
    addPort(sf::Vector2f(75, 84), "Out", consolas, false);

}

void ALUGraph::update(ArithmeticLogicUnit& alu)
{
}

void ALUGraph::draw(sf::RenderWindow& window,
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

    window.draw(points, states);

    window.draw(title, states);

}
