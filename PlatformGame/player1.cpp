#include "player1.h"

using namespace Entidade;

Player1::Player1(sf::Vector2f pos, sf::Vector2f spee) :
	Entity(pos, spee),
	contAnimation(0)
{
	rect.setPosition(pos);

	sprite.setTexture(*(Data::getInstance()->getPlayer1Texture()));
	sprite.setPosition(rect.getPosition());
}
Player1::~Player1()
{
}

void Player1::movementation()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (position.x >= 48))
	{
		speed.x = -walkSpeed;
		position.x += speed.x;
		isLookingRight = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		speed.x = walkSpeed;
		position.x += speed.x;
		isLookingRight = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		jump();

	rect.setPosition(position);
	sprite.setPosition(position);

	spriteAnimation();
}

void Player1::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Player1::spriteAnimation()
{
	sf::Time elapsed = clock.getElapsedTime();
	if (elapsed.asSeconds() >= 0.3)
	{
		contAnimation++;
		clock.restart();
	}
	if (contAnimation > 2)
		contAnimation= 0;
	sprite.setTextureRect(sf::IntRect(47 * contAnimation, 48, 47, 48));
}