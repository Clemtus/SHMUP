#pragma once

#include "Enemy.h"

const string TEXTURE_FREEKAZOID = "sprite/Boss.png";
const int free_health = 3;
const float free_speed = 2;
const float speedProjectileFree = 7;

class Freekazoid :
	public Enemy
{
public:
	Freekazoid();
	void Ennemy_Deplacement();
	Vector2f Enemy_Position_Spawn();
};
