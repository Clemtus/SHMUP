#include "Projectile.h"

Projectile::Projectile(Spatialship *vaisseau, string Texture)
{
	int posX = (vaisseau->GetSprite().getPosition().x) + (vaisseau->GetTexture().getSize().x - _texture.getSize().x) / 2;
	int posY = vaisseau->GetSprite().getPosition().y - vaisseau->GetTexture().getSize().y / 2;

	_texture.loadFromFile(Texture);
	_sprite.setTexture(_texture);
	_sprite.setPosition(posX, posY);
}

void Projectile::Projectile_Deplacement(float delta)
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
