#include "Vehicle.h"

int Vehicle::GetHealth()
{
	return _health;
}

void Vehicle::SetHealth(int health)
{
	_health= health;
}

void Vehicle::Taking_Damage(int damage)
{
	_health -= damage;
}

int Vehicle::GetDamage()
{
	return _damage;
}

void Vehicle::setDamage(int damage)
{
	_damage = damage;
}

float Vehicle::GetSpeedProjectile()
{
	return _speedProjectile;
}

void Vehicle::SetSpeedProjectile(float speed)
{
	_speedProjectile = speed;
}
