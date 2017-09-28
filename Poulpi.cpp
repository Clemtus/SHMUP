#include "Poulpi.h"

Poulpi::Poulpi()
{
	_texture.loadFromFile(TEXTURE_POULPI);
	_sprite.setTexture(_texture);
	_sprite.setPosition(Enemy_Position_Spawn());

	SetHealth(poulpi_health);
	SetSpeed(poulpi_speed);

	SetSpeedProjectile(speedProjectilePoulpi);

	if (_sprite.getPosition().x > (screenW / 2)) {
		_direction = RIGHT_DOWN_P;
	}
	else {
		_direction = LEFT_DOWN_P;
	}
}

void Poulpi::Ennemy_Deplacement()
{
	if (_sprite.getPosition().x < 0) {
		SetDirection(RIGHT_DOWN_P);
	}
	else if (_sprite.getPosition().y > screenW/ 2) {
		if (GetDirection() == RIGHT_DOWN_P) {
			SetDirection(LEFT_UP_P);
		}
		else {
			SetDirection(RIGHT_UP_P);
		}
	}
	else if (_sprite.getPosition().x + _texture.getSize().x > screenW) {
		if (GetDirection() == RIGHT_UP_P) {
			SetDirection(LEFT_UP_P);
		}
		else if (GetDirection() == LEFT_UP_P) {
			SetDirection(RIGHT_UP_P);
		}
		else {
			SetDirection(LEFT_DOWN_P);
		}	
	}

	_sprite.move(GetDirection().x, GetDirection().y * GetSpeed());
}

Vector2f Poulpi::Enemy_Position_Spawn()
{
	int zone_spawn = rand() % 2;
	if (zone_spawn) {
		float posX = screenW + 5;
		float posY = rand() % 20;
		return Vector2f(posX, posY);
	}
	else {
		float posX = -5;
		float posY = rand() % 20;
		return Vector2f(posX, posY);
	}
}

Vector2f Poulpi::GetDirection()
{
	return _direction;
}

void Poulpi::SetDirection(Vector2f direction)
{
	_direction = direction;
}

