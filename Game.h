#pragma once

#include <vector>
#include <map>

#include "Spatialship.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Enumeration.h"
#include "Freekazoid.h"
#include "Polaroid.h"
#include "Explosion.h"

using namespace std; 


class Game
{
private:
	Spatialship *_vaisseau;
	vector<Projectile *> _projectileBoard;
	vector<Enemy *> _enemyBoard;
	vector<Explosion *> _explosionBoard;
	Clock _pTimeVaisseau;
	Clock _pTimeEnemy;
	Clock _eTimeSpawn;

	map<int, vector<EnemyTypeEnum>> _enemyLevelBoard;
	int _indexBoardEnemyLevel = 0;

public:
	Game(float screenW, float screenH);
	
	/* START GETTER / SETTER */
	Spatialship* GetVaisseau();
	void SetVaisseau(Spatialship *vso);
	
	vector<Enemy *> GetEnemyBoard();
	void AddEnemyBoard(Enemy* ennemi);
	void ClearEnemyBoard();

	vector<Projectile *> GetProjectileBoard();
	void AddProjectileBoard(Projectile* projectile);

	vector<Explosion *> GetExplosionBoard();
	void AddExplosionBoard(Explosion* explosion);

	map<int, vector<EnemyTypeEnum>> GetEnemyLevelBoard();
	void AddEnemyLevelBoard(int level, vector<EnemyTypeEnum> enemyBoard);
	int GetSizeEnemyLevelBoard(int level);

	int GetIndexBoardEnemyLevel();
	void IncrementIndexBoardEnemyLevel();
	void ReniIndexBoardEnemyLevel();
	
	int GetNbEnemy();
	/* END GETTER / SETTER */


	// GESTION DU CLAVIER
	void KB_Management(float screenW);


	// PROJECTILES
		// DEPLACEMENT PROJECTILES
	void Projectile_Management();

		// COLLISION PROJECTILES
	bool Entity_Collision(Entity entityOne, Entity entityTwo);
	void Projectile_Collision_Enemy();
	void Erase_Object();
	void Collision();


	// ENNEMIES
		// GENERATION ENNEMIES
	void Enemy_Generation(float screenW, int level);
	Enemy* Enemy_Spawn(EnemyTypeEnum type);
		// GENERATION TIR ENNEMIES
	void Enemy_Shot();
		// DEPLACEMENT ENNEMIES
	void Enemy_Management(float screenH, int level);

	// EXPLOSION
		//AFFICHAGE EXPLOSION
	void Explosion_Generation(Vector2f position);
		// SUPPRESION DES EXPLOSIONS
	void Explosion_Management();
};
