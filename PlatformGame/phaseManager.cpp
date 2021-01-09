#include "phaseManager.h"

using PhaseMap::PhaseManager;

PhaseManager::PhaseManager() :
    phaseMap1("../PlatformGame/data/phaseMap/PhaseMapsJson/phaseMap1.json"),
    phaseMap2("../PlatformGame/data/phaseMap/PhaseMapsJson/phaseMap2.json"),
    player1({ 2 * 48, 27 * 48 }, { 0,0 }, 100),
    player2({ 3 * 48, 27 * 48 }, { 0,0 }, 100)
{
}

PhaseManager::~PhaseManager()
{
}
int PhaseManager::Start(sf::RenderWindow& window, const string player1Name, const string player2Name, const bool multiplayer)
{
    if (!phaseMap1.loadPhaseMap())
        return EXIT_GAME;
    if (!phaseMap2.loadPhaseMap())
        return EXIT_GAME;

    phaseMap1.setPlayer1(&player1);
    phaseMap2.setPlayer1(&player1);
    if (multiplayer)
    {
        phaseMap1.setPlayer2(&player2);
        phaseMap2.setPlayer2(&player2);
    }

    int option = 0;
    while (option >= 0)
    {
        if (option == 0)
        {
            phaseMap1.update();
            option = phaseMap1.render(window);
        }
        else if (option == 2)
        {
            phaseMap2.update();
            option = phaseMap2.render(window);
        }
    }
    return -1;
}

void PhaseManager::resetEverything()
{
    player1.setPosition({ 2 * 48, 27 * 48 });
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