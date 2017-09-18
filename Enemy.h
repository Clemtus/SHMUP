#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "Vehicle.h"
#include "Projectile.h"

const string TEXTURE_PROJECTILE = "sprite/ProjectileVso.png";

const Vector2f LEFT_DOWN_P = Vector2f(-10, 1);
const Vector2f RIGHT_DOWN_P = Vector2f(10, 1);
const Vector2f DOWN_P = Vector2f(0, 1);
const Vector2f UP_P = Vector2f(0, -1);

class Enemy :
	public Vehicle
{
private:
	int _indexPattern;
protected: 
	Vector2f _pattern[6];
public:
	virtual void Ennemy_Deplacement() = 0;

	int GetIndexPattern();
	void IncrementIndexPattern();
	void ReniIndexPattern();
};
