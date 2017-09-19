#include "Projectile.h"

Projectile::Projectile(Vehicle *vehicle, string Texture, DirectionEnumProjectile Direction)
{
	_direction = Direction;
	_touch = false;
	SetSpeed(vehicle->GetSpeedProjectile());
	
	float posX = (vehicle->GetSprite().getPosition().x) + (vehicle->GetTexture().getSize().x - _texture.getSize().x) / 2;
	float posY;
	if (Direction == TIR_VAISSEAU) {
		posY = vehicle->GetSprite().getPosition().y - vehicle->GetTexture().getSize().y / 2;
	}
	else {
		posY = vehicle->GetSprite().getPosition().y + vehicle->GetTexture().getSize().y;
	}
	
	_texture.loadFromFile(Texture);
	_sprite.setTexture(_texture);
	_sprite.setPosition(posX, posY);
}

void Projectile::Projectile_Deplacement()
{
	_sprite.move(0, GetSpeed() * _direction);
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
