#pragma once
#include "Vehicle.h"
#include "Projectile.h"
#include "Enumeration.h"

#pragma region Constante
const string TEXTURE_SPATIALSHIP = "sprite/Spatialship.png";
const string TEXTURE_PROJECTILE_SPATIALSHIP = "sprite/ProjectileVso.png";
#pragma endregion Constante

class Spatialship :
	public Vehicle
{
private:
	Texture _textureProjectile;
public:
	Spatialship(float screenW, float screenH);

	void Vaisseau_Deplacement(DirectionEnum Direction);

	Projectile* Spatialship_Create_Projectile();
};

