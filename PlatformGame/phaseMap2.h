#pragma once

#include "phaseMapGeneral.h"

namespace PhaseMap
{
	class PhaseMap2 : public PhaseMapGeneral
	{
	public:
		PhaseMap2(std::string path = "");
		~PhaseMap2();

		void update() override;
		int render(sf::RenderWindow& window) override;

		virtual void renderPhaseBackGround(sf::RenderWindow& window) override;
	};
}