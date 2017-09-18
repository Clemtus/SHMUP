#include "Enemy.h"

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


