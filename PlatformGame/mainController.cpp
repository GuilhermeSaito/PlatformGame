#include "mainController.h"

MainController::MainController()
{
	window.create(sf::VideoMode(1080, 720), "Arudina's Game");
	window.setFramerateLimit(60);
    
    Start();
}

MainController::~MainController()
{
}

void MainController::Start()
{
	int controller = 0;

	switcher.push_back(&splashScreen);
	switcher.push_back(&openMenu);
	switcher.push_back(&characterSelection);


	while (controller >= 0)
	{
		if (controller != PHASE_MANAGER)
			controller = switcher[controller]->Start(window);
		else
			controller = phaseManager.Start(window, characterSelection.getPlayer1Name(), characterSelection.getPlayer2Name(), characterSelection.getIsMultiplayer());
			
	}

	window.close();
}