#include "phaseManager.h"

using PhaseMap::PhaseManager;

PhaseManager::PhaseManager() :
    phaseMap1("../PlatformGame/data/phaseMap/PhaseMapsJson/phaseMap1.json"),
    phaseMap2("../PlatformGame/data/phaseMap/PhaseMapsJson/phaseMap2.json"),
    phaseMap3("../PlatformGame/data/phaseMap/PhaseMapsJson/phaseMap3.json"),
    phaseMap4("../PlatformGame/data/phaseMap/PhaseMapsJson/phaseMap4.json"),
    player1({ 2 * 48, 27 * 48 }, { 0,0 }, 100),
    player2({ 3 * 48, 27 * 48 }, { 0,0 }, 100),
    needToLoadPhase(true)
{
}

PhaseManager::~PhaseManager()
{
    ResetALL();
}
int PhaseManager::Start(sf::RenderWindow& window, const string player1Name, const string player2Name, const bool multiplayer)
{
    if (loadPhaseMap(multiplayer) == EXIT_GAME)
        return EXIT_GAME;

    // Esse ainda vai mudar, porque vou passar a escolha da fase do CharacterSelection
    int phase = PHASE2;
    while (phase >= 0)
    {
        switch (phase)
        {
        case PHASE1:
            phaseMap1.update(phase);
            phaseMap1.render(window, phase);
            break;
        case PHASE2:
            phaseMap2.update(phase);
            phaseMap2.render(window, phase);
            break;
        case PHASE3:
            phaseMap3.update(phase);
            phaseMap3.render(window, phase);
            break;
        case PHASE4:
            phaseMap4.update(phase);
            phaseMap4.render(window, phase);
            break;
        
        case PLAYER_DIE:
            return showPlayerDie(window);

        default:
            return EXIT_GAME;
        }
    }
    return EXIT_GAME;
}

int PhaseManager::loadPhaseMap(const bool multiplayer)
{
    if (needToLoadPhase)
    {
        if (!phaseMap1.loadPhaseMap())
            return EXIT_GAME;
        if (!phaseMap2.loadPhaseMap())
            return EXIT_GAME;
        if (!phaseMap3.loadPhaseMap())
            return EXIT_GAME;
        if (!phaseMap4.loadPhaseMap())
            return EXIT_GAME;
    }
    phaseMap1.setPlayer1(&player1);
    phaseMap2.setPlayer1(&player1);
    phaseMap3.setPlayer1(&player1);
    phaseMap4.setPlayer1(&player1);
    if (multiplayer)
    {
        phaseMap1.setPlayer2(&player2);
        phaseMap2.setPlayer2(&player2);
        phaseMap3.setPlayer2(&player2);
        phaseMap4.setPlayer2(&player2);
    }

    phaseMap1.resetEverythingForTransition();
    phaseMap2.resetEverythingForTransition();
    phaseMap3.resetEverythingForTransition();
    phaseMap4.resetEverythingForTransition();
    return 1;
}

int PhaseManager::showPlayerDie(sf::RenderWindow& window)
{
    normalizeView(window);

    ResetALL();

    window.clear();
    sf::Sprite playerDie;
    playerDie.setTexture(*(Data::getInstance()->getPlayerDieBackGroundTexture()));
    playerDie.setPosition(sf::Vector2f(window.getSize().x / 2 - window.getSize().x / 4, window.getSize().y / 2 - window.getSize().y / 4));
    window.draw(playerDie);
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
                return EXIT_GAME;
            }
    }
}

void PhaseManager::normalizeView(sf::RenderWindow& window)
{
    sf::View normalView(sf::Vector2f(window.getSize().x / 2 , window.getSize().y / 2), sf::Vector2f(1080, 720));
    window.setView(normalView);
}

void PhaseManager::ResetALL()
{
    phaseMap1.ResetAll();
    phaseMap2.ResetAll();
    phaseMap3.ResetAll();
    phaseMap4.ResetAll();

    needToLoadPhase = false;
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