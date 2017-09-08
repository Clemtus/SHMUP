#include "Vehicle.h"

int Vehicle::GetHealth()
{
	return _health;
}

void Vehicle::SetHealth(int health)
{
	_health = health;
}

int Vehicle::GetDamage()
{
	return _damage;
}

void Vehicle::setDamage(int damage)
{
	_damage = damage;
}
