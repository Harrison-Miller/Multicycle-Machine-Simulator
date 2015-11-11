#include "RegisterGraph.h"
#include <sstream>

RegisterGraph::RegisterGraph(std::string name,
    sf::Vector2f pos,
    sf::Font& consolas,
    bool big,
    bool writebit) :
    Graph(pos, consolas, name, sf::Vector2f(big ? 30 : 60, 30))
{
    numText.setFont(consolas);
    numText.setColor(sf::Color(136, 206, 250));
    numText.setCharacterSize(20);
    numText.setPosition(0, 0);
    numText.setString("0");
    numText.setOrigin((int)numText.getLocalBounds().width/2+2, (int)numText.getLocalBounds().height/2);
    numText.setPosition(15, 23);
    fadeOut = false;
    last = 0;

    if(!big)
    {
        numText.setCharacterSize(10);
        numText.setOrigin((int)numText.getLocalBounds().width/2, (int)numText.getLocalBounds().height/2);
        numText.setPosition(30, 28);

    }

    addPort(sf::Vector2f(0, 30), "In", consolas, true);
    addPort(sf::Vector2f(big ? 30 : 60, 30), "Out", consolas, false);

    if(writebit)
    {
        addPort(sf::Vector2f(big ? 15 : 30, 0), "Write", consolas, false);

    }

}

void RegisterGraph::update(Register& reg)
{
    std::stringstream ss;
    ss << reg.stored;
    std::string str;
    ss >> str;

    hover[0].setString(str);
    hover[1].setString(str);

    if(reg.stored != last)
    {
        if(fadeOut)
        {
            numText.setString(nextValue);

        }

        last = reg.stored;
        nextValue = str;
        fadeOut = true;
        fadeTime.restart();

    }

    if(hover.size() > 2)
    {
        ss.clear();
        ss << reg.inputs[1];
        ss >> str;
        hover[2].setString(str);

    }

}

void RegisterGraph::updateNum()
{
    if(fadeOut)
    {
        float t = fadeTime.getElapsedTime().asSeconds();
        float r = 1-(t/0.75);

        sf::Color c = numText.getColor();
        c.a = r*255;

        if(t/0.75 > 1)
        {
            c.a = 0;
            fadeOut = false;
            fadeTime.restart();
            numText.setString(nextValue);
            numText.setOrigin((int)numText.getLocalBounds().width/2+2, (int)numText.getLocalBounds().height/2);

        }

        numText.setColor(c);

    }
    else
    {
        float t = fadeTime.getElapsedTime().asSeconds();
        float r = t/0.75;
        if(r > 1)
        {
            numText.setColor(sf::Color(136, 206, 250));
            return;

        }

        sf::Color c = numText.getColor();
        c.a = r*255;
        numText.setColor(c);

    }

}

void RegisterGraph::draw(sf::RenderWindow& window,
    sf::RenderStates states)
{
    updateNum();

    Graph::draw(window, states);

    states.transform *= getTransform();

    window.draw(numText, states);

}
