#include "Freekazoid.h"

Freekazoid::Freekazoid()
{
	_texture.loadFromFile(TEXTURE_FREEKAZOID);
	_sprite.setTexture(_texture);

	_sprite.setPosition(Enemy_Position_Spawn());
	SetHealth(free_health);
	SetSpeed(free_speed);
}

void Freekazoid::Ennemy_Deplacement()
{
	_sprite.move(DOWN_P * GetSpeed());
}

Vector2f Freekazoid::Enemy_Position_Spawn()
{
	float posX = rand() % (int(screenW) - _texture.getSize().x);
	float posY = (_texture.getSize().y - 5);
	return Vector2f(posX, -posY);
}
