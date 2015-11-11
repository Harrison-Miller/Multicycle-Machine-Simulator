#include "AndGateGraph.h"
#include <sstream>

AndGateGraph::AndGateGraph(sf::Vector2f pos,
    sf::Font& consolas) :
    Graph(pos, consolas, "And", sf::Vector2f(30, 30))
{
    upper.setSize(sf::Vector2f(0, 15));
    upper.setFillColor(sf::Color(153, 255, 153));
    upper.setPosition(15, 0);
    upOn = false;

    lower.setSize(sf::Vector2f(0, 15));
    lower.setFillColor(sf::Color(153, 255, 153));
    lower.setPosition(30, 0);
    lowOn = false;

    shine.setSize(sf::Vector2f(5, 30));
    shine.setFillColor(sf::Color(255, 255, 255, 175));

    addPort(sf::Vector2f(30, 20), "A", consolas, false);
    addPort(sf::Vector2f(30, 40), "B", consolas, false);

    addPort(sf::Vector2f(0, 30), "Q", consolas, true);

    st = 0;

}

void AndGateGraph::update(AndGate& gate)
{
    int a = gate.inputs[AndGate::A];
    int b = gate.inputs[AndGate::B];

    upOn = a != 0 ? true : false;
    lowOn = b != 0 ? true : false;

    std::stringstream ss;
    ss << a;
    std::string str;
    ss >> str;
    hover[0].setString(str);

    ss.clear();
    ss << b;
    ss >> str;
    hover[1].setString(str);

    ss.clear();

    ss << (a&b);
    ss >> str;
    hover[2].setString(str);

}

void AndGateGraph::updateBars()
{
    sf::Vector2f upSize = upper.getSize();
    if(upOn && upSize.x < 30)
    {
        upSize.x+=5;
        upper.setSize(upSize);

        upper.setPosition(30-upSize.x, 15);

    }
    else if(!upOn && upSize.x > 0)
    {
        upSize.x-=5;
        upper.setSize(upSize);

        upper.setPosition(30-upSize.x, 15);
    }

    sf::Vector2f lowSize = lower.getSize();
    if(lowOn && lowSize.x < 30)
    {
        lowSize.x+=5;
        lower.setSize(lowSize);

        lower.setPosition(30-lowSize.x, 30);

    }
    else if(!lowOn && lowSize.x > 0)
    {
        lowSize.x-=5;
        lower.setSize(lowSize);

        lower.setPosition(30-lowSize.x, 30);

    }

    st++;

    if(upOn && lowOn)
    {
        int k = st%50;
        if(k > 0 && k < 16)
        {
            shine.setPosition(30-k*2, 15);

        }
        else
        {
            shine.setPosition(30, 15);

        }

    }

}

void AndGateGraph::draw(sf::RenderWindow& window,
    sf::RenderStates states)
{
    Graph::draw(window, states);

    updateBars();

    states.transform *= getTransform();

    window.draw(upper, states);
    window.draw(lower, states);

    if(upOn && lowOn && st%50 < 16)
    {
        window.draw(shine, states);

    }

}
