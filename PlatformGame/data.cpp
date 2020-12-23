#include "data.h"

Data* Data::instance = NULL;

Data::Data()
{
	if (!splashScreen.loadFromFile("../PlatformGame/data/erase.png"))
		EXIT_FAILURE;
	if (!openMenuBackGround.loadFromFile("../PlatformGame/data/imageOpenMenu.png"))
		EXIT_FAILURE;
	if (!openMenuBackGround2.loadFromFile("../PlatformGame/data/possibleSplashScreen.jpg"))
		EXIT_FAILURE;

	if (!openMenufont.loadFromFile("../PlatformGame/data/fonts/TurretRoad-Medium.ttf"))
		EXIT_FAILURE;

	if (!notImplementedYet.loadFromFile("../PlatformGame/data/notImplementedYet.png"))
		EXIT_FAILURE;
}

Data::~Data()
{
	delete instance;
}

Data* Data::getInstance()
{
	if (instance == NULL)
		instance = new Data;
	return instance;
}

sf::Texture* Data::getSplashScreenTexture()
{
	return& splashScreen;
}
sf::Texture* Data::getOpenMenuBackGround()
{
	return& openMenuBackGround;
}
sf::Texture* Data::getOpenMenuBackGround2()
{
	return&openMenuBackGround2;
}

sf::Font* Data::getOpenMenufont()
{
	return& openMenufont;
}

sf::Texture* Data::getNotImplementedYet()
{
	return& notImplementedYet;
}