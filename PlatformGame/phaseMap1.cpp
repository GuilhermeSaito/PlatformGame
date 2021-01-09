#include "phaseMap1.h"

using namespace PhaseMap;

PhaseMap1::PhaseMap1(std::string path) :
    PhaseMapGeneral(path)
{
    // Transforming the image to 1080 x 1440
    for (int i = 0; i < 6; i++)
    {
        sf::Sprite* sprite = new sf::Sprite;
        sprite->setTexture(*(Data::getInstance()->getBeginnerPhaseBackGround()));
        sprite->setScale(sf::Vector2f(0.5625, 1.5));
        sprite->setPosition(sf::Vector2f(1080 * i, 48*4));
        phaseBackGroundSprite.push_back(sprite);
    }
}
PhaseMap1::~PhaseMap1()
{
    
    for (auto* i : phaseBackGroundSprite)
        delete i;
    phaseBackGroundSprite.clear();
}

void PhaseMap1::update()
{
    collisionManager.startVerifyCollision();
    player1->gravity();
    player1->movementation();
}

int PhaseMap1::render(sf::RenderWindow& window)
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
    renderPhaseBackGround(window);
    player1->draw(window);
	phaseMapManager.draw(window);
    window.display();
    return 0;
}

void PhaseMap1::renderPhaseBackGround(sf::RenderWindow& window)
{
    for (auto* i : phaseBackGroundSprite)
        window.draw(*i);
}