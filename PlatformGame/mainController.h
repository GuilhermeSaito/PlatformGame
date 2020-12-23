#pragma once

#include "SwitchPanel.h"
#include "splashScreen.h"
#include "openMenu.h"

#include <vector>

class MainController
{
private:
	sf::RenderWindow window;
	std::vector<SwitchPanel*> switcher;

	SplashScreen splashScreen;
	StartScreen::OpenMenu openMenu;

public:
	MainController();
	~MainController();

	void Start();
};

