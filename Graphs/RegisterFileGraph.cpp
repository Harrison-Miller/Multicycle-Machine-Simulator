#include "RegisterFileGraph.h"
#include <sstream>
#include <iomanip>
#include <math.h>

RegisterFileGraph::RegisterFileGraph(sf::Vector2f pos,
    sf::Font& consolas) :
    Graph(pos, consolas, "Register File", sf::Vector2f(120, 80))
{
    for(int i = 0; i < 32; i++)
    {
        std::stringstream ss;
        ss << i;
        std::string str;
        ss >> str;

        sf::Text name(str, consolas, 10);
        name.setColor(sf::Color::Black);
        name.setPosition(5, 20 + i*10);

        names.push_back(name);

        sf::Text value("0x00000000", consolas, 10);
        value.setColor(sf::Color::Black);
        value.setPosition(40, 20 + i*10);

        values.push_back(value);

    }

    top = 0;

    upTri = sf::CircleShape(8, 3);
    upTri.setOrigin(8, 8);
    upTri.setRotation(0);
    upTri.setFillColor(sf::Color::Black);
    upTri.setPosition(112, 16+8);

    downTri = sf::CircleShape(8, 3);
    downTri.setOrigin(8, 8);
    downTri.setFillColor(sf::Color::Black);
    downTri.setRotation(180);
    downTri.setPosition(112, 82+4);

}

void RegisterFileGraph::pollEvent(sf::Event& event)
{
    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2f mpos(event.mouseButton.x, event.mouseButton.y);
            sf::Vector2f bup(112, 16+8);
            bup += getPosition();
            sf::Vector2f updiff = mpos - bup;
            float d1 = sqrt(pow(updiff.x, 2) + pow(updiff.y, 2));
            if(d1 <= 8 && top > 0)
            {
                top--;
                reposition();

            }

            sf::Vector2f bdown(112, 82+4);
            bdown += getPosition();
            sf::Vector2f downdiff = mpos - bdown;
            float d2 = sqrt(pow(downdiff.x, 2) + pow(downdiff.y, 2));
            if(d2 <= 8 && top < 26)
            {
                top++;
                reposition();

            }

        }

    }

}

void RegisterFileGraph::reposition()
{
    for(int i = i; i < top+6; i++)
    {
        int k = i-top;
        names[i].setPosition(5, 20 + k*10);
        values[i].setPosition(40, 20 + k*10);

    }

}

void RegisterFileGraph::update(RegisterFile& regs)
{
    for(int i = 0; i < values.size(); i++)
    {
        std::stringstream ss;
        ss << "0x" << std::hex << std::setfill('0') << std::setw(8) << regs.registers[i];
        std::string str;    
        ss >> str;

        values[i].setString(str);

    }

}

void RegisterFileGraph::draw(sf::RenderWindow& window,
    sf::RenderStates states)
{
    Graph::draw(window, states);

    states.transform *= getTransform();

    window.draw(upTri, states);
    window.draw(downTri, states);

    for(int i = top; i < top + 6; i++)
    {
        window.draw(names[i], states);
        window.draw(values[i], states);

    }

}
