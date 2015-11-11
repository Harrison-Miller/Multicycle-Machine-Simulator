#ifndef GRAPH_H_
#define GRAPH_H_

#include <SFML/Graphics.hpp>
#include <math.h>

template <class T>
class Graph : public sf::Transformable
{
public:
    Graph(sf::Vector2f pos,
        sf::Font& consolas,
        std::string titleStr,
        sf::Vector2f size);

    virtual void pollEvent(sf::Event& event);

    virtual void update(T& component) = 0;

    virtual void draw(sf::RenderWindow& window,
        sf::RenderStates states = sf::RenderStates::Default);

    void addPort(sf::Vector2f pos,
        std::string txt,
        sf::Font& font,
        bool left);

    sf::Text title;
    sf::RectangleShape titleBox;

    sf::RectangleShape box;

    std::vector<sf::CircleShape> ports;
    std::vector<sf::Text> hover;
    std::vector<bool> isleft;

};

template <class T>
void Graph<T>::pollEvent(sf::Event& event)
{
    if(event.type == sf::Event::MouseMoved)
    {
        sf::Vector2f mpos(event.mouseMove.x, event.mouseMove.y);
        mpos -= getPosition();
        for(int i = 0; i < ports.size(); i++)
        {
            sf::Vector2f diff = ports[i].getPosition();
            diff -= mpos;
            float d = sqrt(pow(diff.x, 2) + pow(diff.y, 2));
            if(d <= ports[i].getRadius())
            {
                ports[i].setRadius(8);
                ports[i].setOrigin(8, 8);
                hover[i].setColor(sf::Color::Black);

            }
            else
            {
                ports[i].setRadius(4);
                ports[i].setOrigin(4, 4);
                hover[i].setColor(sf::Color::Transparent);

            }

        }

    }

}

template <class T>
Graph<T>::Graph(sf::Vector2f pos,
    sf::Font& consolas,
    std::string titleStr,
    sf::Vector2f size)
{
    setPosition(pos);

    title.setString(titleStr);
    title.setFont(consolas);
    title.setCharacterSize(10);
    title.setColor(sf::Color::Black);
    title.move(5, 0);

    titleBox.setSize(sf::Vector2f(size.x, 15));
    titleBox.setOutlineColor(sf::Color::Black);
    titleBox.setOutlineThickness(1);

    box.setSize(size);
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(1);
    box.move(0, 15);

}

template <class T>
void Graph<T>::draw(sf::RenderWindow& window,
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

    window.draw(box, states);
    window.draw(titleBox, states);
    window.draw(title, states);
}

template <class T>
void Graph<T>::addPort(sf::Vector2f pos,
        std::string txt,
        sf::Font& font,
        bool left)
{
    sf::CircleShape port(4);
    port.setFillColor(sf::Color::Black);
    port.setOrigin(4, 4);
    port.setPosition(pos);

    ports.push_back(port);

    isleft.push_back(left);

    sf::Text text(txt, font, 10);
    text.setColor(sf::Color::Transparent);
    float offset = left ? -(text.getLocalBounds().width + 8) : 8;
    float yoffset = left ? 0 : -12;
    text.setPosition(pos.x + offset, pos.y + yoffset);

    hover.push_back(text);

}

#endif /*GRAPH*/
