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
	if (GetIndexPattern() < 5) {
		_sprite.move(_pattern[GetIndexPattern()].x * (GetSpeed() / 2), _pattern[GetIndexPattern()].y * (GetSpeed() * 2));
		IncrementIndexPattern();
	}
	else {
		_sprite.move(_pattern[GetIndexPattern()].x * (GetSpeed() / 2), _pattern[GetIndexPattern()].y * (GetSpeed() * 2));
		ReniIndexPattern();
	}
}
