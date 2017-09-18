#include "Freekazoid.h"

Freekazoid::Freekazoid(float posX)
{
	_texture.loadFromFile(TEXTURE_FREEKAZOID);
	_sprite.setTexture(_texture);
	_sprite.setPosition(posX, 0);
	SetHealth(free_health);
	SetSpeed(free_speed);
}

void Freekazoid::Ennemy_Deplacement()
{
}



