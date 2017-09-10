#pragma once
#include "Entity.h"
#include "Vehicle.h"
#include "Enumeration.h"



class Projectile :
	public Entity
{
private:
	bool _touch;
	int _direction;

public:
	Projectile(Vehicle *vehicle, string Texture, DirectionEnumProjectile Direction);

	/* START GETTER / SETTER */
	bool GetTouch();
	void SetTouch(int touch);

	int GetDirection();
	void SetDirection(int direction);
	/* END GETTER / SETTER */

	void Projectile_Deplacement();
};

