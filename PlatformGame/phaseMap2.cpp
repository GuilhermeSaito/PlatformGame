#include "phaseMap2.h"

#include "phaseMap1.h"

using namespace PhaseMap;

PhaseMap2::PhaseMap2(std::string path) :
    phaseMapManager(path)
{
}
PhaseMap2::~PhaseMap2()
{
}

#include "SwitchPanel.h"
int PhaseMap2::draw(sf::RenderWindow& window)
{
    sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
    rectangle.setSize(sf::Vector2f(100.f, 100.f));
    rectangle.setPosition(sf::Vector2f(0, 0));


    if (phaseMapManager.loadMapTileProprieties())
        while (1)
        {
            sf::View player1View(sf::Vector2f(rectangle.getPosition().x + 1000, rectangle.getPosition().y + 1000), sf::Vector2f(1120, 672));
            window.setView(player1View);

            sf::Event event;
            if (window.pollEvent(event))
                switch (event.type)
                {
                case sf::Event::Closed:
                    return -1;
                }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                rectangle.move(-10.f, 0.f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                rectangle.move(10.f, 0.f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                rectangle.move(0.f, -10.f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                rectangle.move(0.f, 10.f);
            window.clear();
            window.draw(rectangle);
            phaseMapManager.draw(window);
            window.display();
        }
}