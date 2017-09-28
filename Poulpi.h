#pragma once
#include "Enemy.h"

const string TEXTURE_POULPI = "sprite/Poulpi.png";
const int poulpi_health = 1;
const float poulpi_speed = 3;
const float speedProjectilePoulpi = 5.5;

class Poulpi :
	public Enemy
{
private:
	Vector2f _direction;
public:
	Poulpi();

	void Ennemy_Deplacement();
	Vector2f Enemy_Position_Spawn();

	Vector2f GetDirection();
	void SetDirection(Vector2f direction);
};

