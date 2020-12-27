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
		sf::Text menu1;
		sf::Text menu2;
		sf::Text menu3;
		sf::Text menu4;

		string player1Name;
		string player2Name;

		// Just to show the player how is the phase
		sf::Sprite beginnerPhaseSprite;
		sf::Sprite blueOceanPhaseSprite;
		sf::Sprite cavePhaseSprite;
		sf::Sprite deathPhaseSprite;

		sf::Sprite player1Sprite;
		sf::Sprite player2Sprite;

		bool isMultiplayer;

	public:
		CharacterSelection();
		~CharacterSelection();

		int Start(sf::RenderWindow& window) override;
		int phaseSelection(sf::RenderWindow& window);
		int characterSelection(sf::RenderWindow& window);
		int nameCharacterSelection(sf::RenderWindow& window);

		void updateMenuCollor(int controller, sf::RenderWindow& window, bool isPhaseSelection);
		void player1Animation(int& contAnimationPlayer1, int& controller);
		void player2Animation(int& contAnimationPlayer2, int& controller);

		void player1NameEnter(int& totalChar1, sf::Event& event);
		void player2NameEnter(int& totalChar2, sf::Event& event);

		int notImplementedYet(sf::RenderWindow& window);
	};
}
