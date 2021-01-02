#include "phaseManager.h"

using PhaseMap::PhaseManager;

PhaseManager::PhaseManager() : 
    phaseMap1("../PlatformGame/data/phaseMap/PhaseMapsJson/tse1.json"),
    phaseMap2("../PlatformGame/data/phaseMap/PhaseMapsJson/tse2.json")
{
}

PhaseManager::~PhaseManager()
{
}
int PhaseManager::Start(sf::RenderWindow& window, const string player1Name, const string player2Name, const bool multiplayer)
{
    if (phaseMap1.draw(window) == 2)
        return phaseMap2.draw(window);
}


int PhaseManager::notImplementedYet(sf::RenderWindow& window)
{
    window.clear();
    sf::Sprite notImplementedYet;
    notImplementedYet.setTexture(*(Data::getInstance()->getNotImplementedYet()));
    notImplementedYet.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
    window.draw(notImplementedYet);
    window.display();

    while (true)
    {
        sf::Event event;
        if (window.pollEvent(event))
            switch (event.type)
            {
            case sf::Event::MouseButtonPressed:
            case sf::Event::KeyPressed:
                return OPEN_MENU;
            case sf::Event::Closed:
                return -1;
            }
    }
}