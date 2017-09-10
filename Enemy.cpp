#include "Enemy.h"

void Enemy::Ennemy_Deplacement()
{
	if (GetIndexPattern() < 5) {
		_sprite.move(_pattern[GetIndexPattern()].x * (GetSpeed() / 2), _pattern[GetIndexPattern()].y * (GetSpeed() * 2));
		IncrementIndexPattern();
	}
	else {
		_sprite.move(_pattern[GetIndexPattern()].x * (GetSpeed() / 2), _pattern[GetIndexPattern()].y * (GetSpeed() * 2));
		ReniIndexPattern();
	}
}

int Enemy::GetIndexPattern()
{
	return _indexPattern;
}

void Enemy::IncrementIndexPattern()
{
	_indexPattern++;
}

void Enemy::ReniIndexPattern()
{
	_indexPattern = 0;
}


