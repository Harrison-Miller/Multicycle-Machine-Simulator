#include "MemoryGraph.h"
#include <sstream>

MemoryGraph::MemoryGraph(sf::Vector2f pos,
    sf::Font& consolas) :
    Graph(pos, consolas, "Memory", sf::Vector2f(80, 80))
{
    addPort(sf::Vector2f(30, 0), "Read", consolas, false);
    addPort(sf::Vector2f(60, 0), "Write", consolas, false);
    addPort(sf::Vector2f(0, 30), "Address", consolas, true);
    addPort(sf::Vector2f(0, 60), "Data", consolas, true);
    addPort(sf::Vector2f(80, 40), "Out", consolas, false);

}

void MemoryGraph::update(MemoryUnit& mem)
{
    int mread = mem.inputs[2];

    std::stringstream ss;
    ss << mem.inputs[2];
    std::string str;
    ss >> str;
    hover[0].setString(str);

    ss.clear();
    ss << mem.inputs[3];
    ss >> str;
    hover[1].setString(str);

    ss.clear();
    ss << mem.inputs[0];
    ss >> str;
    hover[2].setString(str);

    ss.clear();
    ss << mem.inputs[1];
    ss >> str;
    hover[3].setString(str);

    if(mread)
    {
        ss.clear();
        ss << mem.memory[mem.inputs[0]];
        ss >> str;
        hover[4].setString(str);

    }

}

void MemoryGraph::draw(sf::RenderWindow& window,
    sf::RenderStates states)
{
    Graph::draw(window, states);

}
