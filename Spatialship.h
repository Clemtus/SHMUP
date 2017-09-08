#pragma once

#include "Vehicle.h"
#include "Enumeration.h"

const string TEXTURE_SPATIALSHIP = "sprite/Spatialship.png";

class Spatialship :
	public Vehicle
{
public:
	Spatialship(float screenW, float screenH);

	void Vaisseau_Deplacement(DirectionEnum Direction);
};

