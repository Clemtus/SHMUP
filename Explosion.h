#pragma once
#include "Entity.h"

const string TEXTURE_EXPLOSION = "sprite/Explosion.png";

class Explosion :
	public Entity
{
private:
	int _etatRect;
public:
	Explosion(Vector2f position);

	int GetEtatRect();
	void SetEtatRect(int rect);
	void IncrementEtatRect();

	void Explo_Anim();
};

