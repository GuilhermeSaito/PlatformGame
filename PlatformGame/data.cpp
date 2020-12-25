#include "data.h"

Data* Data::instance = NULL;

Data::Data()
{
	if (!splashScreen.loadFromFile("../PlatformGame/data/erase.png"))
		EXIT_FAILURE;
	if (!splashScreen2.loadFromFile("../PlatformGame/data/possibleSplashScreen.jpg"))
		EXIT_FAILURE;
	if (!openMenuBackGround.loadFromFile("../PlatformGame/data/imageOpenMenu.png"))
		EXIT_FAILURE;
	if (!beginnerPhaseBackGround.loadFromFile("../PlatformGame/data/possiblePhasesBackGround/beginnerPhaseBackGround.jpg"))
		EXIT_FAILURE;
	if (!blueOceanPhaseBackGround.loadFromFile("../PlatformGame/data/possiblePhasesBackGround/blueOceanPhaseBackGround.png"))
		EXIT_FAILURE;
	if (!cavePhaseBackGround.loadFromFile("../PlatformGame/data/possiblePhasesBackGround/cavePhaseBackGround.png"))
		EXIT_FAILURE;
	if (!deathPhaseBackGround.loadFromFile("../PlatformGame/data/possiblePhasesBackGround/deathPhaseBackGround.png"))
		EXIT_FAILURE;
	if (!fireVolcanoPhaseBackGround.loadFromFile("../PlatformGame/data/possiblePhasesBackGround/fireVolcanoPhaseBackGround.png"))
		EXIT_FAILURE;
	if (!forestPhaseBackGround.loadFromFile("../PlatformGame/data/possiblePhasesBackGround/forestPhaseBackGround.jpg"))
		EXIT_FAILURE;
	if (!speranzaPhaseBackGround.loadFromFile("../PlatformGame/data/possiblePhasesBackGround/speranzaPhaseBackGround.jpg"))
		EXIT_FAILURE;
	if (!player1Image.loadFromFile("../PlatformGame/data/players/Player1Image.png"))
		EXIT_FAILURE;
	if (!player2Image.loadFromFile("../PlatformGame/data/players/player2Image.png"))
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
sf::Texture* Data::getSplashScreenTexture2()
{
	return& splashScreen2;
}
sf::Texture* Data::getOpenMenuBackGround()
{
	return& openMenuBackGround;
}
sf::Texture* Data::getBeginnerPhaseBackGround()
{
	return& beginnerPhaseBackGround;
}
sf::Texture* Data::getBlueOceanPhaseBackGround()
{
	return& blueOceanPhaseBackGround;
}
sf::Texture* Data::getCavePhaseBackGround()
{
	return& cavePhaseBackGround;
}
sf::Texture* Data::getDathPhaseBackGround()
{
	return& deathPhaseBackGround;
}
sf::Texture* Data::getFireVolcanoPhaseBackGround()
{
	return& fireVolcanoPhaseBackGround;
}
sf::Texture* Data::getForestPhaseBackGround()
{
	return& forestPhaseBackGround;
}
sf::Texture* Data::getSperanzaPhaseBackGround()
{
	return& speranzaPhaseBackGround;
}
sf::Texture* Data::getPlayer1Texture()
{
	return& player1Image;
}
sf::Texture* Data::getPlayer2Texture()
{
	return& player2Image;
}

sf::Font* Data::getOpenMenufont()
{
	return& openMenufont;
}

sf::Texture* Data::getNotImplementedYet()
{
	return& notImplementedYet;
}