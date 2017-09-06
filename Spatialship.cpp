#include "Spatialship.h"

Spatialship::Spatialship(float screenW, float screenH)
{
	// TEXTURE
	_texture.loadFromFile(TEXTURE_SPATIALSHIP);
	_sprite.setTexture(_texture);
	_sprite.setPosition((screenW / 2) - (_texture.getSize().x / 2), screenH - _texture.getSize().y);

	// CARACTERISTIQUES
	SetHealth(5);
	SetSpeed(4.5);

	// TEXTURE DU VAISSEAU
	_textureProjectile.loadFromFile(TEXTURE_PROJECTILE_SPATIALSHIP);
}

void Spatialship::Vaisseau_Deplacement(DirectionEnum Direction)
{
	_sprite.move(GetSpeed() * Direction, 0);
}


Projectile* Spatialship::Spatialship_Create_Projectile()
{
	class Projectile *projectile = NULL;

	projectile->GetSprite().setTexture(_textureProjectile);
	/*int posX = (_sprite.getPosition().x) + (_texture.getSize().x / 2) - (_textureProjectile.getSize().x / 2);
	int posY = _sprite.getPosition().y;
	projectile->GetSprite().setPosition(posX, posY);*/

	return projectile;
}
