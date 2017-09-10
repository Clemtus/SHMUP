#include "Spatialship.h"

Spatialship::Spatialship(float screenW, float screenH)
{
	// TEXTURE
	_texture.loadFromFile(TEXTURE_SPATIALSHIP);
	_sprite.setTexture(_texture);
	_sprite.setPosition((screenW / 2) - (_texture.getSize().x / 2), screenH - _texture.getSize().y);

	// CARACTERISTIQUES
	SetHealth(health);
	SetSpeed(speed);
	SetSpeedProjectile(speedProjectile);
	
}

void Spatialship::Vaisseau_Deplacement(DirectionEnumKB Direction)
{
	_sprite.move(GetSpeed() * Direction, 0);
}

