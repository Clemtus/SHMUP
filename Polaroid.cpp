#include "Polaroid.h"


Polaroid::Polaroid(float posX)
{
	_texture.loadFromFile(TEXTURE_POLAROID);
	_sprite.setTexture(_texture);
	_sprite.setPosition(posX, 0);
	
	SetHealth(pola_health);
	SetSpeed(pola_speed);

	SetSpeedProjectile(speedProjectilePola);

	// INITIALISATION DU PATTERN
	_pattern[0] = LEFT_DOWN_P;
	_pattern[1] = LEFT_DOWN_P;
	_pattern[2] = RIGHT_DOWN_P;
	_pattern[3] = UP_P;
	_pattern[4] = RIGHT_DOWN_P;
	_pattern[5] = DOWN_P;

	ReniIndexPattern();
}

