#pragma once

#include "phaseMapGeneral.h"

namespace PhaseMap
{
	class PhaseMap1 : public PhaseMapGeneral
	{
	public:
		PhaseMap1(std::string path = "");
		~PhaseMap1();

		void update() override;
		int render(sf::RenderWindow& window) override;

		virtual void renderPhaseBackGround(sf::RenderWindow& window) override;
	};
}
