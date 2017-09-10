#pragma once
#include "Entity.h"

class Vehicle :
	public Entity
{
private:
	int _health;
	int _damage;
	float _speedProjectile;

public:
	int GetHealth();
	void SetHealth(int health);
	void Taking_Damage(int damage);

	int GetDamage();
	void setDamage(int damage);

	float GetSpeedProjectile();
	void SetSpeedProjectile(float speed);
};

