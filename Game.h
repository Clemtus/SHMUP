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

const int DELAY_MISSILE_VSO = 300;
const int DELAY_MISSILE_ENEMY = 300;
const string TEXTURE_PROJECTILE_SPATIALSHIP = "sprite/ProjectileVso.png";


class Game
{
private:
	Spatialship *_vaisseau;
	vector<Projectile> _projectileBoard;
	vector<Enemy *> _enemyBoard;
	vector<Explosion> _explosionBoard;
	Clock _pTimeVaisseau;
	Clock _pTimeEnemy;

public:
	Game(float screenW, float screenH);
	
	/* START GETTER / SETTER */
	Spatialship* GetVaisseau();
	void SetVaisseau(Spatialship *vso);
	
	vector<Enemy *> GetEnemyBoard();
	void AddEnemyBoard(Enemy* ennemi);
	void ClearEnemyBoard();

	vector<Projectile> GetProjectileBoard();
	void AddProjectileBoard(Projectile* projectile);

	vector<Explosion> GetExplosionBoard();
	void AddExplosionBoard(Explosion* explosion);

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
	Enemy* Enemy_Spawn(float posX, EnemyTypeEnum type);
		// GENERATION TIR ENNEMIES
	void Enemy_Shot();
		// DEPLACEMENT ENNEMIES
	void Enemy_Management(float screenH);

	// EXPLOSION
		//AFFICHAGE EXPLOSION
	void Explosion_Generation(Vector2f position);
		// SUPPRESION DES EXPLOSIONS
	void Explosion_Management();
};
