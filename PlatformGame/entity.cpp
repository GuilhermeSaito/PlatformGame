#include "entity.h"

using namespace Entidade;

Entity::Entity(sf::Vector2f pos, sf::Vector2f spee) :
	position(pos),
	speed(spee),
	walkSpeed(10),
	onGround(false),
	jumpSpeed(-20),
	gravityAcceleration((float)1.1),
	isLookingRight(true)
{
	rect.setSize({ 48, 48 });	
}
Entity::~Entity()
{
}

const sf::Vector2f Entity::getPosition() const { return position; }
void Entity::setPosition(const sf::Vector2f pos) { position = pos; }
const sf::Vector2f Entity::getSpeed() const { return speed; }
void Entity::setSpeed(const sf::Vector2f spee) { speed = spee; }
								// Rectangle located at  (x Position, Y Position) with a Size of (X rectSize, Y rectSize)
sf::FloatRect Entity::getBoundBox() { return sf::FloatRect(position.x, position.y, rect.getSize().x, rect.getSize().y); }
const bool Entity::getOnGround() const { return onGround; }
void Entity::setOnGround(const bool onG) { onGround = onG; }
void Entity::jump()
{
	if (onGround)
	{
		speed.y += jumpSpeed;
		onGround = false;
	}
}
void Entity::setIsLookingRight(const bool r) { isLookingRight = r; }