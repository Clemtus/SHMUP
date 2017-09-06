#include "Entity.h"

Texture Entity::GetTexture()
{
	return _texture;
}

void Entity::SetTexture(Texture texture)
{
	_texture = texture;
}

Sprite Entity::GetSprite()
{
	return _sprite;
}

float Entity::GetSpeed()
{
	return _speed;
}

void Entity::SetSpeed(float speed)
{
	_speed = speed;
}
