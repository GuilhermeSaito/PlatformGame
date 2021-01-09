#include "phaseMap2.h"

using namespace PhaseMap;

PhaseMap2::PhaseMap2(std::string path) :
    PhaseMapGeneral(path)
{
    // Transforming the image to 1080 x 720

}
PhaseMap2::~PhaseMap2()
{
}

void PhaseMap2::update()
{
    collisionManager.startVerifyCollision();
    player1->gravity();
    player1->movementation();
}

int PhaseMap2::render(sf::RenderWindow& window)
{
    sf::View player1View(sf::Vector2f(player1->getPosition()), sf::Vector2f(1120, 672));
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

void PhaseMap2::renderPhaseBackGround(sf::RenderWindow& window)
{

}