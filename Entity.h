#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Entity
{
private:
	float _speed;

protected:
	Texture _texture;
	Sprite _sprite;

public:
	Texture GetTexture();
	void SetTexture(Texture texture);

	Sprite GetSprite();

	float GetSpeed();
	void SetSpeed(float speed);
};

