#include "Projectile.h"


Projectile::Projectile(string Texture)
{
	_texture.loadFromFile(Texture);
	_sprite.setTexture(_texture);
}

Projectile* Projectile::Create_Projectile_Vaisseau(Spatialship *vaisseau, Projectile *projectile)
{
	int posX = (vaisseau->GetSprite().getPosition().x) + (vaisseau->GetTexture().getSize().x / 2) - (projectile->GetTexture().getSize().x / 2);
	int posY = vaisseau->GetSprite().getPosition().y;
	projectile->GetSprite().setPosition(posX, posY);

	return projectile;
}

void Projectile::Projectile_Deplacement()
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
