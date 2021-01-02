#pragma once

// just for the OPEN_MENU
#include "SwitchPanel.h"
#include "phaseMap1.h"
#include "phaseMap2.h"
using std::string;


namespace PhaseMap
{
	class PhaseManager
	{
	private:
		PhaseMap1 phaseMap1;
		PhaseMap2 phaseMap2;

	public:
		PhaseManager();
		~PhaseManager();

		int Start(sf::RenderWindow& window, const string player1Name, const string player2Name, const bool multiplayer);

		int notImplementedYet(sf::RenderWindow& window);
	};
}