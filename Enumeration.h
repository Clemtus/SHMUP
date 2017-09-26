#pragma once

// DIFFERENTE ENUMERATION
typedef enum {
	LEFT = -1,
	RIGHT = 1
} DirectionEnumKB;

typedef enum {
	TIR_ENEMY = 1,
	TIR_VAISSEAU = -1
}DirectionEnumProjectile;

typedef enum {
	FREEKAZOID_ENEMY = 0,
	POLAROID_ENEMY = 1
}EnemyTypeEnum;

// CONSTANTE
const float screenW = 600.0;
const float screenH = 600.0;

const int DELAY_MISSILE_VSO = 300;
const int DELAY_MISSILE_ENEMY = 500;
const int DELAY_SPAWN_ENEMY = 4800;

const string TEXTURE_PROJECTILE_SPATIALSHIP = "sprite/ProjectileVso.png";

// DEFINITION DES TABLEAUX D'ENNEMIES DES DIFFERENTS NIVEAUX
const vector<EnemyTypeEnum> enemyLevelOneBoard { POLAROID_ENEMY, POLAROID_ENEMY, POLAROID_ENEMY, POLAROID_ENEMY };
const vector<EnemyTypeEnum> enemyLevelTwoBoard { POLAROID_ENEMY, FREEKAZOID_ENEMY, POLAROID_ENEMY, POLAROID_ENEMY, FREEKAZOID_ENEMY, POLAROID_ENEMY, FREEKAZOID_ENEMY };
const vector<EnemyTypeEnum> enemyLevelTreeBoard { POLAROID_ENEMY };