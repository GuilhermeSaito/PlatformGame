#pragma once

#include "PhaseMapManager.h"
#include "player1.h"
#include "CollisionManager.h"

namespace PhaseMap
{
	class PhaseMapGeneral
	{
	protected:
		Tiles::PhaseMapManager phaseMapManager;

		Entidade::Player1* player1;

		CollisionManager collisionManager;

		std::vector<sf::Sprite*> phaseBackGroundSprite;

	public:
		PhaseMapGeneral(std::string path = "");
		virtual ~PhaseMapGeneral();

		virtual void update();
		virtual int render(sf::RenderWindow& window);
		bool loadPhaseMap();

	protected:
		virtual void renderPhaseBackGround(sf::RenderWindow& window);

	public:

		void setPlayer1(Entidade::Player1* p1);
	};
}