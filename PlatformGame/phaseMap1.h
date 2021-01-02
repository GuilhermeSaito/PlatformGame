#pragma once

#include "PhaseMapManager.h"

namespace PhaseMap
{
	class PhaseMap1
	{
	private:
		Tiles::PhaseMapManager phaseMapManager;
	
	public:
		PhaseMap1(std::string path = "");
		~PhaseMap1();

		int draw(sf::RenderWindow& window);
	};
}
