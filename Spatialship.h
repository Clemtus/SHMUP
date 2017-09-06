#pragma once
#include "Vehicle.h"
#include "Enumeration.h"

#pragma region Constante
const string TEXTURE_SPATIALSHIP = "sprite/Spatialship.png";
#pragma endregion Constante

class Spatialship :
	public Vehicle
{
public:
	Spatialship(float screenW, float screenH);

	void Vaisseau_Deplacement(DirectionEnum Direction);
};

