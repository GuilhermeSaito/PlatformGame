#pragma once

#include "SwitchPanel.h"
#include "splashScreen.h"
#include "openMenu.h"
#include "characterSelection.h"

#include <vector>

class MainController
{
private:
	sf::RenderWindow window;
	std::vector<SwitchPanel*> switcher;

	SplashScreen splashScreen;
	StartScreen::OpenMenu openMenu;
	StartScreen::CharacterSelection characterSelection;

public:
	MainController();
	~MainController();

	void Start();
};

