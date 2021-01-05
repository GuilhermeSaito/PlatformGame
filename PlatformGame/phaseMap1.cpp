#include "phaseMap1.h"

using namespace PhaseMap;

PhaseMap1::PhaseMap1(std::string path) :
	phaseMapManager(path),
    player1(NULL)
{
}
PhaseMap1::~PhaseMap1()
{
}

void PhaseMap1::update()
{
    collisionManager.startVerifyCollision();
    player1->gravity();
    player1->movementation();
}

int PhaseMap1::render(sf::RenderWindow& window)
{                                               // 
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
bool PhaseMap1::loadPhaseMap()
{
    bool flag = phaseMapManager.loadMapTileProprieties();
    collisionManager.setPhaseMapManager(&phaseMapManager);
    return flag;
}

void PhaseMap1::setPlayer1(Entidade::Player1* p1) 
{ 
    player1 = p1; 
    collisionManager.setPlayer1(p1);
}