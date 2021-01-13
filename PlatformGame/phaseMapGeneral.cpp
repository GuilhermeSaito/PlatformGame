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

void PhaseMapGeneral::update(int& controller)
{
}

void PhaseMapGeneral::render(sf::RenderWindow& window, int& controller)
{      
}
bool PhaseMapGeneral::loadPhaseMap()
{
    bool flag = phaseMapManager.loadMapTileProprieties();
    collisionManager.setPhaseMapManager(&phaseMapManager);
    return flag;
}

void PhaseMapGeneral::renderPhaseBackGround(sf::RenderWindow& window) {}

void PhaseMapGeneral::phaseTransition(int& contoller)
{
    if (contoller != PHASE4)
    {
        if (player2 != NULL)
            if (player2->getPosition().x >= 131 * TILE_SIZE)
            {
                resetEverything();
                contoller++;
            }
        if (player1->getPosition().x >= 131 * TILE_SIZE)
        {
            resetEverything();
            contoller++;
        }
    }
}

void PhaseMapGeneral::resetEverything()
{
    player1->setPosition({ 2 * TILE_SIZE, 27 * TILE_SIZE });
    if (player2 != NULL)
        player2->setPosition({ 2 * TILE_SIZE, 27 * TILE_SIZE });
}

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