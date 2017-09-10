#pragma once

#include "Enemy.h"

const string TEXTURE_POLAROID = "sprite/Enemy.png";
const int pola_health = 1;
const float pola_speed = 3;
const float speedProjectilePola = 5.5;

class Polaroid :
	public Enemy
{
public:
	Polaroid(float posX);
};

