#pragma once

#include "SwitchPanel.h"
#include "data.h"

namespace StartScreen
{
	class OpenMenu : public SwitchPanel
	{
	private:
		sf::Sprite backGroundSprite;

		sf::Text menu1;
		sf::Text menu2;
		sf::Text menu3;
		sf::Text menu4;

	public:
		OpenMenu();
		~OpenMenu();

		int Start(sf::RenderWindow& window) override;

		void updateMenuCollor(int controller);

		int notImplementedYet(sf::RenderWindow& window);
	};
}