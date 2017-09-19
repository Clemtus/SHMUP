#pragma once

#include "Enemy.h"

const string TEXTURE_POLAROID = "sprite/Enemy.png";
const int pola_health = 1;
const float pola_speed = 3;
const float speedProjectilePola = 5.5;

class Polaroid :
	public Enemy
{
private:
	Vector2f _direction;
public:
	Polaroid();
	void Ennemy_Deplacement();
	Vector2f Enemy_Position_Spawn();

	Vector2f GetDirection();
	void SetDirection(Vector2f direction);
};

