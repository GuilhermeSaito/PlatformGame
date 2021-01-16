#pragma once

#include <SFML/Graphics.hpp>

#define EXIT_GAME -1
#define SPLASH_SCREEN 0
#define OPEN_MENU 1
#define CHARACTER_SELECTION 2
#define PHASE_MANAGER 3

#define PHASE1 11
#define PHASE2 12
#define PHASE3 13
#define PHASE4 14

class SwitchPanel
{
public:
	SwitchPanel() {}
	~SwitchPanel() {}

	virtual int Start(sf::RenderWindow& window) = 0;
};