#pragma once

#include "SwitchPanel.h"
#include "data.h"

#include <iostream>
using std::string;

namespace StartScreen
{
	class CharacterSelection : public SwitchPanel
	{
	private:
		// Just to show the player how is the phase
		sf::Sprite phase1BackGround;
		sf::Sprite phase2BackGround;

		sf::Text menu1;
		sf::Text menu2;
		sf::Text menu3;
		sf::Text menu4;

		string player1Name;
		string player2Name;

	public:
		CharacterSelection();
		~CharacterSelection();

		int Start(sf::RenderWindow& window) override;
		int phaseSelection(sf::RenderWindow& window);
		int characterSelection(sf::RenderWindow& window);
	};
}
