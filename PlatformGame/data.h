#pragma once

#include <SFML/Graphics.hpp>

class Data
{
private:
	Data();
	static Data* instance;

	sf::Texture splashScreen;
	sf::Texture splashScreen2;
	sf::Texture openMenuBackGround;
	sf::Texture beginnerPhaseBackGround;
	sf::Texture blueOceanPhaseBackGround;
	sf::Texture cavePhaseBackGround;
	sf::Texture deathPhaseBackGround;
	sf::Texture fireVolcanoPhaseBackGround;
	sf::Texture forestPhaseBackGround;
	sf::Texture speranzaPhaseBackGround;
	sf::Texture player1Image;
	sf::Texture player2Image;

	sf::Font openMenufont;

	sf::Texture notImplementedYet;

public:
	~Data();
	static Data* getInstance();

	sf::Texture* getSplashScreenTexture();
	sf::Texture* getSplashScreenTexture2();
	sf::Texture* getOpenMenuBackGround();
	sf::Texture* getBeginnerPhaseBackGround();
	sf::Texture* getBlueOceanPhaseBackGround();
	sf::Texture* getCavePhaseBackGround();
	sf::Texture* getDathPhaseBackGround();
	sf::Texture* getFireVolcanoPhaseBackGround();
	sf::Texture* getForestPhaseBackGround();
	sf::Texture* getSperanzaPhaseBackGround();
	sf::Texture* getPlayer1Texture();
	sf::Texture* getPlayer2Texture();

	sf::Font* getOpenMenufont();

	sf::Texture* getNotImplementedYet();
};
