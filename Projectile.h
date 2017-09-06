#pragma once
#include "Entity.h"

class Projectile :
	public Entity
{
private:
	bool _touch;
	int _direction;
public:
	Projectile();

	void Projectile_Deplacement();

	bool GetTouch();
	void SetTouch(int touch);

	int GetDirection();
	void SetDirection(int direction);
};

