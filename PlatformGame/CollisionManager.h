#pragma once

#include "player1.h"
#include "PhaseMapManager.h"

#define TILE_SIZE 48

class CollisionManager
{
private:
	Entidade::Player1* player1;
	PhaseMap::Tiles::PhaseMapManager* phaseMapManager;

public:
	CollisionManager();
	~CollisionManager();

	void startVerifyCollision();

private:
	void player1CollisionX();
	void player1CollisionY();

public:
	void setPlayer1(Entidade::Player1* p1);
	void setPhaseMapManager(PhaseMap::Tiles::PhaseMapManager* phaseMapMa);
};

