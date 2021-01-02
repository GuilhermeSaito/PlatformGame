#pragma once

#include "PhaseMapManager.h"

namespace PhaseMap
{
	class PhaseMap2
	{
	private:
		Tiles::PhaseMapManager phaseMapManager;

	public:
		PhaseMap2(std::string path = "");
		~PhaseMap2();

		int draw(sf::RenderWindow& window);
	};
}