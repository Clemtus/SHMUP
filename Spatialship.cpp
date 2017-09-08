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
}

void Spatialship::Vaisseau_Deplacement(DirectionEnum Direction)
{
	_sprite.move(GetSpeed() * Direction, 0);
}

