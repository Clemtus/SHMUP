#pragma once
#include "Entity.h"
#include "Spatialship.h"

class Projectile :
	public Entity
{
private:
	bool _touch;
	int _direction;
public:
	Projectile(Spatialship *vaisseau, string Texture);

	/* START GETTER / SETTER */
	bool GetTouch();
	void SetTouch(int touch);

	int GetDirection();
	void SetDirection(int direction);
	/* END GETTER / SETTER */

	void Projectile_Deplacement(float delta);
};

