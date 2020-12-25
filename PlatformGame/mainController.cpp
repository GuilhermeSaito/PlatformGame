#include "mainController.h"

MainController::MainController()
{
	window.create(sf::VideoMode(1080, 720), "Arudina's Game");
    
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
		controller = switcher[controller]->Start(window);

	window.close();
}