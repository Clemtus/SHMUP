#include "Explosion.h"



Explosion::Explosion(Vector2f position)
{
	SetEtatRect(0);

	_texture.loadFromFile(TEXTURE_EXPLOSION);
	_sprite.setTexture(_texture);
	_sprite.setPosition(position);
	_sprite.setTextureRect(IntRect(50 * GetEtatRect(), 0, 50, 50));
}

int Explosion::GetEtatRect()
{
	return _etatRect;
}

void Explosion::SetEtatRect(int rect)
{
	_etatRect = rect;
}

void Explosion::IncrementEtatRect()
{
	_etatRect++;
}

void Explosion::Explo_Anim()
{
	IncrementEtatRect();
	_sprite.setTextureRect(IntRect(50 * GetEtatRect(), 0, 50, 50));
}

