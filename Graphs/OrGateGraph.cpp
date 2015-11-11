#include "OrGateGraph.h"
#include <sstream>

OrGateGraph::OrGateGraph(sf::Vector2f pos,
    sf::Font& consolas) :
    Graph(pos, consolas, "Or", sf::Vector2f(30, 30))
{
    bar.setSize(sf::Vector2f(0, 30));
    bar.setFillColor(sf::Color(153, 255, 153));
    upOn = false;
    lowOn = false;

    shine.setSize(sf::Vector2f(5, 30));
    shine.setFillColor(sf::Color(255, 255, 255, 175));

    addPort(sf::Vector2f(30, 20), "A", consolas, false);
    addPort(sf::Vector2f(30, 40), "B", consolas, false);

    addPort(sf::Vector2f(0, 30), "Q", consolas, true);

    st = 0;

}

void OrGateGraph::update(OrGate& gate)
{
    int a = gate.inputs[OrGate::A];
    int b = gate.inputs[OrGate::B];

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

    ss << (a|b);
    ss >> str;
    hover[2].setString(str);

}

void OrGateGraph::updateBars()
{
    bool on = upOn || lowOn;

    sf::Vector2f barSize = bar.getSize();
    if(on && barSize.x < 30)
    {
        barSize.x+=5;
        bar.setSize(barSize);

        bar.setPosition(30-barSize.x, 15);

    }
    else if(!on && barSize.x > 0)
    {
        barSize.x-=5;
        bar.setSize(barSize);

        bar.setPosition(30-barSize.x, 15);
    }

    st++;

    if(on)
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

void OrGateGraph::draw(sf::RenderWindow& window,
    sf::RenderStates states)
{
    Graph::draw(window, states);

    updateBars();

    states.transform *= getTransform();

    window.draw(bar, states);

    if((upOn || lowOn) && st%50 < 16)
    {
        window.draw(shine, states);

    }

}
