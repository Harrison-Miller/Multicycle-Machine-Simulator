#include "MultiplexerGraph.h"
#include <sstream>

MultiplexerGraph::MultiplexerGraph(int inputs,
    sf::Vector2f pos,
    sf::Font& consolas,
    bool seltop) :
    Graph(pos, consolas, "MUX", sf::Vector2f(40, 15*inputs)),
    inputs(inputs)
{
    last = 0;

    for(int i = 0; i < inputs; i++)
    {
        sf::VertexArray wire(sf::LinesStrip, 4);
        wire[0] = sf::Vertex(sf::Vector2f(0, 23 + i*15), sf::Color(220, 220, 220));
        wire[1] = sf::Vertex(sf::Vector2f(20, 23 + i*15), sf::Color(220, 220, 220));
        wire[2] = sf::Vertex(sf::Vector2f(20, 16 + (15*inputs)/2), sf::Color(220, 220, 220));
        wire[3] = sf::Vertex(sf::Vector2f(40, 16 + (15*inputs)/2), sf::Color(220, 220, 220));

        addPort(sf::Vector2f(0, 23 + i*15), "I", consolas, true);

        if(last == i)
        {
            active = wire;
            active[0].color = sf::Color::Red;
            active[1].color = sf::Color::Red;
            active[2].color = sf::Color::Red;
            active[3].color = sf::Color::Red;

        }

        wires.push_back(wire);

    }

    addPort(sf::Vector2f(40, 16 + (15*inputs)/2), "O", consolas, false);
    addPort(sf::Vector2f(20, seltop ? 0 : 16 + 15*inputs), "Sel", consolas, !seltop);

}

void MultiplexerGraph::update(Multiplexer& mux)
{
    int a = mux.inputs[Multiplexer::Sel];
    if(a != last)
    {
        last = a;

        active = wires[a];

        active[0].color = sf::Color::Red;
        active[1].color = sf::Color::Red;
        active[2].color = sf::Color::Red;
        active[3].color = sf::Color::Red;


    }

    for(int i = 0; i < ports.size()-2; i++)
    {
        std::stringstream ss;
        ss << mux.inputs[1+i];
        std::string str;
        ss >> str;
        hover[i].setString(str);

    }

    std::stringstream ss;
    ss << mux.inputs[1+a];
    std::string str;
    ss >> str;
    hover[ports.size()-2].setString(str);

    ss.clear();
    ss << a;
    ss >> str;
    hover[ports.size()-1].setString(str);

}

void MultiplexerGraph::draw(sf::RenderWindow& window,
    sf::RenderStates states)
{
    Graph::draw(window, states);

    states.transform *= getTransform();

    for(int i = 0; i < inputs; i++)
    {
        window.draw(wires[i], states);

    }

    window.draw(active, states);

}
