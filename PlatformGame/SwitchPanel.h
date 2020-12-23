#pragma once

#include <SFML/Graphics.hpp>

#define EXIT_GAME -1
#define SPLASH_SCREEN 0
#define OPEN_MENU 1
#define CHARACTER_SELECTION 2

class SwitchPanel
{
public:
	SwitchPanel() {}
	~SwitchPanel() {}

	virtual int Start(sf::RenderWindow& window) = 0;
};