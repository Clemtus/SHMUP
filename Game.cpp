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

vector<Enemy> Game::GetEnemyBoard()
{
	return _enemyBoard;
}

void Game::AddEnemyBoard(Enemy* ennemi)
{
	_enemyBoard.push_back(*ennemi);
}

void Game::ClearEnemyBoard()
{
	_enemyBoard.clear();
}

vector<Projectile> Game::GetProjectileBoard()
{
	return _projectileBoard;
}

void Game::AddProjectileBoard(Projectile*  projectile)
{
	_projectileBoard.push_back(*projectile);
}

int Game::GetNbEnemy()
{
	return _enemyBoard.size();
}


// GESTION DU CLAVIER
void Game::KB_Management(float screenW)
{
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		if (_vaisseau->GetSprite().getPosition().x > 0.0) {
			_vaisseau->Vaisseau_Deplacement(LEFT);
		}
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			if (_pTimeVaisseau.getElapsedTime().asMilliseconds() >= DELAY_MISSILE_VSO) {
				class Projectile *project = new Projectile(GetVaisseau(), TEXTURE_PROJECTILE_SPATIALSHIP, TIR_VAISSEAU);
				AddProjectileBoard(project);
				_pTimeVaisseau.restart();
			}
		}
	}
	else if(Keyboard::isKeyPressed(Keyboard::Right)){
		if (_vaisseau->GetSprite().getPosition().x < screenW - (_vaisseau->GetTexture().getSize().x)) {
			_vaisseau->Vaisseau_Deplacement(RIGHT);
		}
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			if (_pTimeVaisseau.getElapsedTime().asMilliseconds() >= DELAY_MISSILE_VSO) {
				class Projectile *project = new Projectile(GetVaisseau(), TEXTURE_PROJECTILE_SPATIALSHIP, TIR_VAISSEAU);
				AddProjectileBoard(project);
				_pTimeVaisseau.restart();
			}
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Space)) {
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
	for (vector<Projectile>::iterator it = _projectileBoard.begin();
		it < _projectileBoard.end();) {
		it->Projectile_Deplacement();

		float posY = it->GetSprite().getPosition().y;
		int sizeY = it->GetTexture().getSize().y;

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
	for (vector<Projectile>::iterator projectile_it = _projectileBoard.begin();
		projectile_it < _projectileBoard.end();
		projectile_it++) {
		
		for (vector<Enemy>::iterator enemy_it = _enemyBoard.begin();
			enemy_it < _enemyBoard.end();
			enemy_it++) {
			
			if (Entity_Collision(*projectile_it, *enemy_it)) {
				enemy_it->Taking_Damage(1);
				projectile_it->SetTouch(true);
			}
		}
	}
}
void Game::Erase_Object() {
	for (vector<Enemy>::iterator enemy_it = _enemyBoard.begin();
		enemy_it < _enemyBoard.end();) {
		if (enemy_it->GetHealth() <= 0) {
			enemy_it = _enemyBoard.erase(enemy_it);
		}
		else {
			++enemy_it;
		}
	}

	for (vector<Projectile>::iterator projectile_it = _projectileBoard.begin();
		projectile_it < _projectileBoard.end();) {
		if (projectile_it->GetTouch()) {
			projectile_it = _projectileBoard.erase(projectile_it);
		}
		else {
			++projectile_it;
		}
	}
}
void Game::Collision() {
	Projectile_Collision_Enemy();
	Erase_Object();
}


// ENNEMIES
	// GENERATION ENNEMIES
void Game::Enemy_Generation(float screenW, int level)
{
	ClearEnemyBoard();

	switch (level)
	{
		case 1: {
			float posX = screenW / 8;
			class Enemy* enemy1 = Enemy_Spawn(posX * 1,POLAROID_ENEMY);
			AddEnemyBoard(enemy1);
			class Enemy* enemy2 = Enemy_Spawn(posX * 2, POLAROID_ENEMY);
			AddEnemyBoard(enemy2);
			class Enemy* enemy4 = Enemy_Spawn(posX * 6, POLAROID_ENEMY);
			AddEnemyBoard(enemy4);
			class Enemy* enemy5 = Enemy_Spawn(posX * 7, POLAROID_ENEMY);
			AddEnemyBoard(enemy5);
			break;
		}
	}
}
Enemy* Game::Enemy_Spawn(float posX, EnemyTypeEnum type) {
	class Enemy* enemy = NULL;
	switch (type) {
		case FREEKAZOID_ENEMY: {
			enemy = new Freekazoid(posX);
			break;
		}
		case POLAROID_ENEMY: {
			enemy = new Polaroid(posX);
			break;
		}
	}
	return enemy;
}

	// DEPLACEMENT ENNEMIES
void Game::Enemy_Management(float screenH)
{
	for (vector<Enemy>::iterator it = _enemyBoard.begin();
		it < _enemyBoard.end();) {
		it->Ennemy_Deplacement();

		float posY = it->GetSprite().getPosition().y;
		
		if (posY > screenH) {
			it = _enemyBoard.erase(it);
		}
		else {
			++it;
		}
	}

	int tir = rand() % 100;
	if (tir < 10) {
		class Projectile *project = new Projectile(&_enemyBoard[3], TEXTURE_PROJECTILE_SPATIALSHIP, TIR_ENEMY);
		AddProjectileBoard(project);
		cout << _projectileBoard.size() << endl;
		cout << "TIR" << endl;
	}
}

	


