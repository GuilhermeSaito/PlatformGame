#pragma once

#include "phaseMap1.h"
#include "phaseMap2.h"
#include "phaseMap3.h"
#include "phaseMap4.h"
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
		PhaseMap3 phaseMap3;
		PhaseMap4 phaseMap4;

		Entidade::Player1 player1;
		Entidade::Player2 player2;

		bool needToLoadPhase;

	public:
		PhaseManager();
		~PhaseManager();

		int Start(sf::RenderWindow& window, const string player1Name, const string player2Name, const bool multiplayer);

	private:
		int loadPhaseMap(const bool multiplayer);

		int showPlayerDie(sf::RenderWindow& window);
		void normalizeView(sf::RenderWindow& window);

		void ResetALL();

		int notImplementedYet(sf::RenderWindow& window);
	};
}