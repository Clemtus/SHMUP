#pragma once
#include <vector>

#include "Spatialship.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Enumeration.h"

using namespace std;

class Game
{
private:
	Spatialship *_vaisseau;
	vector<Projectile*> _projectileBoard;
	vector<Enemy*> _enemyBoard;
	Clock _pTimeVaisseau;

public:
	Game(float screenW, float screenH);

	Spatialship* GetVaisseau();
	void SetVaisseau(Spatialship *vso);
	
	vector<Enemy*> GetEnemyBoard();
	void AddEnemyBoard(Enemy* ennemi);

	vector<Projectile*> GetProjectileBoard();
	void AddProjectileBoard(Projectile* projectile);

	// GESTION DU CLAVIER
	void KB_Management(float screenW);
};

