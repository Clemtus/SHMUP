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
	Projectile(string Texture);

	/* START GETTER / SETTER */
	bool GetTouch();
	void SetTouch(int touch);

	int GetDirection();
	void SetDirection(int direction);
	/* END GETTER / SETTER */

	Projectile* Create_Projectile_Vaisseau(Spatialship* vaisseau, Projectile *projectile);
	void Projectile_Deplacement();
};

