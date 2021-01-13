#pragma once

#include "phaseMapGeneral.h"

namespace PhaseMap
{
	class PhaseMap1 : public PhaseMapGeneral
	{
	public:
		PhaseMap1(std::string path = "");
		~PhaseMap1();

		void update(int& controller) override;
		void render(sf::RenderWindow& window, int& controller) override;

	private:
		virtual void renderPhaseBackGround(sf::RenderWindow& window) override;
	};
}
