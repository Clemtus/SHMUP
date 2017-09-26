#include "Polaroid.h"


Polaroid::Polaroid()
{
	
	_texture.loadFromFile(TEXTURE_POLAROID);
	_sprite.setTexture(_texture);
	_sprite.setPosition(Enemy_Position_Spawn());
	
	SetHealth(pola_health);
	SetSpeed(pola_speed);

	SetSpeedProjectile(speedProjectilePola);
	
	if (_sprite.getPosition().x > (screenW / 2)) {
		_direction = RIGHT_DOWN_P;
	}
	else {
		_direction = LEFT_DOWN_P;
	}
}

void Polaroid::Ennemy_Deplacement()
{
	if (_sprite.getPosition().x < 0) {
		SetDirection(RIGHT_DOWN_P);
	}
	else if (_sprite.getPosition().x + _texture.getSize().x > screenW){
		SetDirection(LEFT_DOWN_P);
	}
	
	_sprite.move(GetDirection().x, GetDirection().y * GetSpeed());
}

Vector2f Polaroid::Enemy_Position_Spawn()
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

Vector2f Polaroid::GetDirection()
{
	return _direction;
}

void Polaroid::SetDirection(Vector2f direction)
{
	_direction = direction;
}



