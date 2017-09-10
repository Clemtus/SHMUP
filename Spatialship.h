#pragma once

#include "Vehicle.h"
#include "Enumeration.h"

const string TEXTURE_SPATIALSHIP = "sprite/Spatialship.png";
const float speed = 4.5;
const float speedProjectile = 5.5;
const int health = 5;

class Spatialship :
	public Vehicle
{
public:
	Spatialship(float screenW, float screenH);

	void Vaisseau_Deplacement(DirectionEnumKB Direction);
};

