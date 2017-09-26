#include "Game.h"


Game::Game(float screenW, float screenH)
{
	_vaisseau = new Spatialship(screenW, screenH);
}

Spatialship* Game::GetVaisseau()
{
	return _vaisseau;
}

void Game::SetVaisseau(Spatialship * vso)
{
	_vaisseau = vso;
}

vector<Object*> Game::GetObjectBoard()
{
	return _objectBoard;
}

void Game::AddObjectBoard(Object * object)
{
	_objectBoard.push_back(object);
}

vector<Enemy *> Game::GetEnemyBoard()
{
	return _enemyBoard;
}

void Game::AddEnemyBoard(Enemy* ennemi)
{
	_enemyBoard.push_back(ennemi);
}

void Game::ClearEnemyBoard()
{
	_enemyBoard.clear();
}

vector<Projectile *> Game::GetProjectileBoard()
{
	return _projectileBoard;
}

void Game::AddProjectileBoard(Projectile*  projectile)
{
	_projectileBoard.push_back(projectile);
}

vector<Explosion *> Game::GetExplosionBoard()
{
	return _explosionBoard;
}

void Game::AddExplosionBoard(Explosion * explosion)
{
	_explosionBoard.push_back(explosion);
}

map<int, vector<EnemyTypeEnum>> Game::GetEnemyLevelBoard()
{
	return _enemyLevelBoard;
}

void Game::AddEnemyLevelBoard(int level, vector<EnemyTypeEnum> enemyBoard)
{
	_enemyLevelBoard[level] = enemyBoard;
}

int Game::GetSizeEnemyLevelBoard(int level)
{
	return _enemyLevelBoard[level].size();
}

int Game::GetIndexBoardEnemyLevel()
{
	return _indexBoardEnemyLevel;
}

void Game::IncrementIndexBoardEnemyLevel()
{
	_indexBoardEnemyLevel++;
}

void Game::ReniIndexBoardEnemyLevel()
{
	_indexBoardEnemyLevel = 0;
}

int Game::GetNbEnemy()
{
	return _enemyBoard.size();
}


// GESTION DU CLAVIER
void Game::KB_Management(float screenW)
{
	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::Q)) {
		if (_vaisseau->GetSprite().getPosition().x > 0.0) {
			_vaisseau->Vaisseau_Deplacement(LEFT);
		}
	}
	else if(Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)){
		if (_vaisseau->GetSprite().getPosition().x < screenW - (_vaisseau->GetTexture().getSize().x)) {
			_vaisseau->Vaisseau_Deplacement(RIGHT);
		}
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		if (_pTimeVaisseau.getElapsedTime().asMilliseconds() >= DELAY_MISSILE_VSO) {
			class Projectile *project = new Projectile(GetVaisseau(), TEXTURE_PROJECTILE_SPATIALSHIP, TIR_VAISSEAU);
			AddProjectileBoard(project);
			_pTimeVaisseau.restart();
		}
	}
}


// PROJECTILES
	// DEPLACEMENT PROJECTILES
void Game::Projectile_Management() {	
	for (vector<Projectile *>::iterator it = _projectileBoard.begin();
		it < _projectileBoard.end();) {
		(*it)->Projectile_Deplacement();

		float posY = (*it)->GetSprite().getPosition().y;

		if (posY < 0 || posY > 800) {
			it = _projectileBoard.erase(it);
		}
		else {
			++it;
		}
	}
}
	
	// COLLISION PROJECTILES
bool Game::Entity_Collision(Entity entityOne, Entity entityTwo) {
	FloatRect boudingBoxOne = entityOne.GetSprite().getGlobalBounds();
	FloatRect boudingBoxTwo = entityTwo.GetSprite().getGlobalBounds();

	if (boudingBoxOne.intersects(boudingBoxTwo)) {
		return true;
	}
	else {
		return false;
	}
}
void Game::Projectile_Collision_Enemy() {
	for (vector<Projectile *>::iterator projectile_it = _projectileBoard.begin();
		projectile_it < _projectileBoard.end();
		projectile_it++) {

		// VERIFIE SI LE PROJECTILE VIENS BIEN D'UN ENEMY
		if ((*projectile_it)->GetDirection() == -1) {
			for (vector<Enemy *>::iterator enemy_it = _enemyBoard.begin();
				enemy_it < _enemyBoard.end();
				enemy_it++) {
				if (Entity_Collision(**projectile_it, **enemy_it)) {
					(*enemy_it)->Taking_Damage(1);
					(*projectile_it)->SetTouch(true);
				}
			}
		}
		else {
			if (Entity_Collision(**projectile_it, *GetVaisseau())) {
				GetVaisseau()->Taking_Damage(1);
				(*projectile_it)->SetTouch(true);
				if (_objectBoard.size() > 0) {
					_objectBoard.pop_back();
				}
				
			}
		}
	}
}
void Game::Erase_Object() {
	for (vector<Enemy *>::iterator enemy_it = _enemyBoard.begin();
		enemy_it < _enemyBoard.end();) {
		if ((*enemy_it)->GetHealth() <= 0) {
			// AJOUT EXPLOSION
			Explosion_Generation((*enemy_it)->GetSprite().getPosition());
			enemy_it = _enemyBoard.erase(enemy_it);
		}
		else {
			++enemy_it;
		}
	}

	for (vector<Projectile *>::iterator projectile_it = _projectileBoard.begin();
		projectile_it < _projectileBoard.end();) {
		if ((*projectile_it)->GetTouch()) {
			projectile_it = _projectileBoard.erase(projectile_it);
		}
		else {
			++projectile_it;
		}
	}
	if (!_objectBoard.size()) {
		Explosion_Generation(GetVaisseau()->GetSprite().getPosition());
		cout << "PERDU" << endl;
	}
}
void Game::Collision() {
	Projectile_Collision_Enemy();
	Erase_Object();
}


void Game::Enemy_Generation(int level) {
	int nombreEnemy = 0;
	int index = 0;
	switch (level) {
	case 1:
		nombreEnemy = 1;
		break;
	case 2:
		nombreEnemy = 2;
		break;
	}
	while (index < nombreEnemy && GetIndexBoardEnemyLevel() < GetSizeEnemyLevelBoard(level)) {
		class Enemy* enemy = Enemy_Spawn(_enemyLevelBoard[level][GetIndexBoardEnemyLevel()]);
		AddEnemyBoard(enemy);
		IncrementIndexBoardEnemyLevel();
		index++;
	}
}
Enemy* Game::Enemy_Spawn(EnemyTypeEnum type) {
	class Enemy* enemy = NULL;
	switch (type) {
		case FREEKAZOID_ENEMY: {
			enemy = new Freekazoid();
			break;
		}
		case POLAROID_ENEMY: {
			enemy = new Polaroid();
			break;
		}
	}
	return enemy;
}

	// GENERATION PROJECTILES ENNEMIES
void Game::Enemy_Shot()
{
	if (_pTimeEnemy.getElapsedTime().asMilliseconds() >= DELAY_MISSILE_ENEMY) {
		if (_enemyBoard.size() > 0) {
			for (int indexBoard = 0; indexBoard < _enemyBoard.size(); indexBoard++) {
				int tir = rand() % 2;
				if (tir && _enemyBoard[indexBoard]->GetSprite().getPosition().y < screenH / 2) {
					class Projectile *project = new Projectile(_enemyBoard[indexBoard], TEXTURE_PROJECTILE_SPATIALSHIP, TIR_ENEMY);
					AddProjectileBoard(project);
				}
			}
		}
		_pTimeEnemy.restart();
	}
}
	// DEPLACEMENT ENNEMIES
void Game::Enemy_Management(float screenH, int level)
{
	if ((((_eTimeSpawn.getElapsedTime().asMilliseconds() >= DELAY_SPAWN_ENEMY) || GetEnemyBoard().size() < 1)) && (GetIndexBoardEnemyLevel() < GetSizeEnemyLevelBoard(level))) {
		Enemy_Generation(level);
		_eTimeSpawn.restart();
	}

	for (vector<Enemy *>::iterator it = _enemyBoard.begin();
		it < _enemyBoard.end();) {
		(*it)->Ennemy_Deplacement();

		float posY = (*it)->GetSprite().getPosition().y;
		
		if (posY > screenH) {
			it = _enemyBoard.erase(it);
		}
		else {
			++it;
		}
	}

	Enemy_Shot();
}


// EXPLOSION
	// GENERATION EXPLOSION
void Game::Explosion_Generation(Vector2f position)
{
	class Explosion *explosion = new Explosion(position);
	AddExplosionBoard(explosion);
}
	// SUPPRIMER LES EXPLOSIONS
void Game::Explosion_Management()
{
	for (vector<Explosion *>::iterator it = _explosionBoard.begin();
		it < _explosionBoard.end();) {
		(*it)->Explo_Anim();

		if ((*it)->GetEtatRect() > 20) {
			it = _explosionBoard.erase(it);
		}
		else {
			++it;
		}
	}
}


// VIE
void Game::HealthVaisseau_Initialisation()
{
	int espace = 5;
	for (int index = 0; index < GetVaisseau()->GetHealth(); index++) {
		class Object* health = new Object(TEXTURE_LIFE, espace, 0);
		AddObjectBoard(health);
		espace += 50;
	}
}



	

	


