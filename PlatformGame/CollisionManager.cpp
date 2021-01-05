#include "CollisionManager.h"

CollisionManager::CollisionManager()
{
}
CollisionManager::~CollisionManager()
{
}

void CollisionManager::startVerifyCollision()
{
	player1CollisionX();
	player1CollisionY();
}

void CollisionManager::player1CollisionX()
{
	int i, j;
	for (i = player1->getPosition().x / TILE_SIZE; i < ((player1->getPosition().x + player1->getSize().x) / TILE_SIZE); i++)
	{
		if (!phaseMapManager->isValidTile(i, player1->getPosition().y / TILE_SIZE))
			continue;
		PhaseMap::Tiles::Tile* tempTile = phaseMapManager->getTile(i, player1->getPosition().y / 48);
		if (player1->getBoundBox().intersects(tempTile->getBoundBox()))
		{
			std::cout << "Collision Ocurred! X" << std::endl;
			player1->collisionInX(tempTile);
		}
	}
}
void CollisionManager::player1CollisionY()
{
	int i, j;
	for (j = player1->getPosition().y / TILE_SIZE; j < ((player1->getPosition().y + player1->getSize().y) / TILE_SIZE); j++)
	{
		if (!phaseMapManager->isValidTile(player1->getPosition().x / TILE_SIZE, j))
			continue;
		PhaseMap::Tiles::Tile* tempTile = phaseMapManager->getTile(player1->getPosition().x / TILE_SIZE, j);
		if (player1->getBoundBox().intersects(tempTile->getBoundBox()))
		{
			std::cout << "Collision Ocurred! Y" << std::endl;
			player1->collisionInY(tempTile);
		}
	}
}

void CollisionManager::setPlayer1(Entidade::Player1* p1) { player1 = p1; }
void CollisionManager::setPhaseMapManager(PhaseMap::Tiles::PhaseMapManager* phaseMapMa) { phaseMapManager = phaseMapMa; }