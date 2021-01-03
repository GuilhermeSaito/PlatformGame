#pragma once

#include "PhaseMapManager.h"
#include "player1.h"

namespace PhaseMap
{
	class PhaseMap1
	{
	private:
		Tiles::PhaseMapManager phaseMapManager;

		Entidade::Player1* player1;
	
	public:
		PhaseMap1(std::string path = "");
		~PhaseMap1();

		void update();
		int render(sf::RenderWindow& window);
		bool loadPhaseMap();
	
		void setPlayer1(Entidade::Player1* p1);
	};
}
