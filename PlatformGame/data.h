#pragma once

#include <SFML/Graphics.hpp>

class Data
{
private:
	Data();
	static Data* instance;

	sf::Texture splashScreen;
	sf::Texture openMenuBackGround;
	sf::Texture openMenuBackGround2;
	sf::Texture phase1BackGround;
	sf::Texture phase2BackGround;

	sf::Font openMenufont;

	sf::Texture notImplementedYet;

public:
	~Data();
	static Data* getInstance();

	sf::Texture* getSplashScreenTexture();
	sf::Texture* getOpenMenuBackGround();
	sf::Texture* getOpenMenuBackGround2();
	sf::Texture* getPhase1BackGround();
	sf::Texture* getPhase2BackGround();

	sf::Font* getOpenMenufont();

	sf::Texture* getNotImplementedYet();
};

