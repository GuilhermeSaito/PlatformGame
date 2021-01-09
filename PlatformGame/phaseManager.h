#pragma once

// just for the OPEN_MENU
#include "SwitchPanel.h"
#include "phaseMap1.h"
#include "phaseMap2.h"
#include "player1.h"
#include "Player2.h"
using std::string;

namespace PhaseMap
{
	class PhaseManager
	{
	private:
		PhaseMap1 phaseMap1;
		PhaseMap2 phaseMap2;

		Entidade::Player1 player1;
		Entidade::Player2 player2;

	public:
		PhaseManager();
		~PhaseManager();

		int Start(sf::RenderWindow& window, const string player1Name, const string player2Name, const bool multiplayer);

	private:
		void resetEverything();

		int notImplementedYet(sf::RenderWindow& window);
	};
}