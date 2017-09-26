#include "Object.h"


Object::Object(String Texture, float posX, float posY)
{
	SetSpeed(0);
	_texture.loadFromFile(Texture);
	_sprite.setTexture(_texture);
	_sprite.setPosition(posX, posY);
}

