#include "phaseMapGeneral.h"

using namespace PhaseMap;

PhaseMapGeneral::PhaseMapGeneral(std::string path) :
    phaseMapManager(path),
    player1(NULL),
    player2(NULL)
{
}
PhaseMapGeneral::~PhaseMapGeneral()
{
}

void PhaseMapGeneral::update()
{
    collisionManager.startVerifyCollision();
    player1->gravity();
    player1->movementation();
}

int PhaseMapGeneral::render(sf::RenderWindow& window)
{                                               
    sf::View player1View(sf::Vector2f(player1->getPosition()), sf::Vector2f(1120, 672));
    window.setView(player1View);

    sf::Event event;
    if (window.pollEvent(event))
        switch (event.type)
        {
        case sf::Event::Closed:
            return -1;
        case sf::Event::MouseButtonPressed:
            return 2;
        }

    window.clear();
    player1->draw(window);
    phaseMapManager.draw(window);
    window.display();
    return 0;
}
bool PhaseMapGeneral::loadPhaseMap()
{
    bool flag = phaseMapManager.loadMapTileProprieties();
    collisionManager.setPhaseMapManager(&phaseMapManager);
    return flag;
}

void PhaseMapGeneral::renderPhaseBackGround(sf::RenderWindow& window) {}

void PhaseMapGeneral::setPlayer1(Entidade::Player1* p1)
{
    player1 = p1;
    collisionManager.setPlayer1(p1);
}
void PhaseMapGeneral::setPlayer2(Entidade::Player2* p2)
{
    player2 = p2;
    collisionManager.setPlayer2(p2);
}