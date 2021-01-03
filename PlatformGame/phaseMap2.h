#pragma once

#include "PhaseMapManager.h"
#include "player1.h"

namespace PhaseMap
{
	class PhaseMap2
	{
	private:
		Tiles::PhaseMapManager phaseMapManager;

		Entidade::Player1* player1;

	public:
		PhaseMap2(std::string path = "");
		~PhaseMap2();

		void update();
		int render(sf::RenderWindow& window);
		bool loadPhaseMap();

		void setPlayer1(Entidade::Player1* p1);
	};
}