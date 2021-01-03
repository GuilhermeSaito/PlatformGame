#include "phaseMap2.h"

using namespace PhaseMap;

PhaseMap2::PhaseMap2(std::string path) :
    phaseMapManager(path),
    player1(NULL)
{
}
PhaseMap2::~PhaseMap2()
{
}

void PhaseMap2::update()
{
    player1->movementation();
}

int PhaseMap2::render(sf::RenderWindow& window)
{
    sf::View player1View(sf::Vector2f(player1->getPosition().x, 335), sf::Vector2f(1120, 672));
    window.setView(player1View);

    sf::Event event;
    if (window.pollEvent(event))
        switch (event.type)
        {
        case sf::Event::Closed:
            return -1;
        }
    window.clear();
    player1->draw(window);
    phaseMapManager.draw(window);
    window.display();
    return 2;
}
bool PhaseMap2::loadPhaseMap()
{
    return phaseMapManager.loadMapTileProprieties();
}


void PhaseMap2::setPlayer1(Entidade::Player1* p1) { player1 = p1; }