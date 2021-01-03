#pragma once

#include "data.h"

namespace Entidade
{
	class Entity
	{
	protected:
		sf::Vector2f position;
		sf::Vector2f speed;
		float walkSpeed;
		
		sf::RectangleShape rect;
		bool onGround;
		float jumpSpeed;
		float gravityAcceleration;

		sf::Sprite sprite;
		bool isLookingRight;

	public:
		Entity(sf::Vector2f pos = { 0 , 0 }, sf::Vector2f spee = { 0, 0 });
		~Entity();

		const sf::Vector2f getPosition() const;
		void setPosition(const sf::Vector2f pos);
		const sf::Vector2f getSpeed() const;
		void setSpeed(const sf::Vector2f spee);

		sf::FloatRect getBoundBox();
		const bool getOnGround() const;
		void setOnGround(const bool onG);
		void jump();
		void setIsLookingRight(const bool r);
	};
}