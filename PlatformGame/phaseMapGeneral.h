#pragma once

#include "PhaseMapManager.h"
#include "player1.h"
#include "Player2.h"
#include "CollisionManager.h"

// Just for the defines
#include "SwitchPanel.h"

#define PHASE1 1
#define PHASE2 2
#define PHASE3 3
#define PHASE4 4

#define PLAYER_DIE 66

namespace PhaseMap
{
	class PhaseMapGeneral
	{
	protected:
		Tiles::PhaseMapManager phaseMapManager;

		Entidade::Player1* player1;
		Entidade::Player2* player2;

		CollisionManager collisionManager;

		std::vector<sf::Sprite*> phaseBackGroundSprite;

	public:
		PhaseMapGeneral(std::string path = "");
		virtual ~PhaseMapGeneral();

		virtual void update(int& controller);
		virtual void render(sf::RenderWindow& window, int& controller);
		bool loadPhaseMap();

	protected:
		virtual void renderPhaseBackGround(sf::RenderWindow& window);
		void phaseTransition(int& contoller);
		bool isPlayerDead();

	public:
		void resetEverythingForTransition();

		void setPlayer1(Entidade::Player1* p1);
		void setPlayer2(Entidade::Player2* p2);

		void ResetAll();
	};
}
