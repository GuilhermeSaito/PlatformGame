#pragma once

#include "SwitchPanel.h"
#include "data.h"
#include "save.h"

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

		SaveGame::Save save;
		json jSave;

	public:
		OpenMenu();
		~OpenMenu();

		int Start(sf::RenderWindow& window) override;

	private:
		void updateMenuCollor(int controller);

	public:
		json getContinueSave();

		int notImplementedYet(sf::RenderWindow& window);
	};
}