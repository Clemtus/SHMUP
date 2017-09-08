#pragma once
#include "Entity.h"

class Vehicle :
	public Entity
{
private:
	int _health;
	int _damage;

public:
	int GetHealth();
	void SetHealth(int health);

	int GetDamage();
	void setDamage(int damage);
};

