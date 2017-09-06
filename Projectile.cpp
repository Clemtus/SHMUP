#include "Projectile.h"

Projectile::Projectile()
{
}

void Projectile::Projectile_Deplacement()
{
}

bool Projectile::GetTouch()
{
	return _touch;
}

void Projectile::SetTouch(int touch)
{
	_touch = touch;
}

int Projectile::GetDirection()
{
	return _direction;
}

void Projectile::SetDirection(int direction)
{
	_direction = direction;
}
