#include "Game.h"

#pragma region constante
const int DELAY_MISSILE_VSO = 300;
const string TEXTURE_PROJECTILE_SPATIALSHIP = "sprite/ProjectileVso.png";
#pragma endregion constante

Game::Game(float screenW, float screenH)
{
	_vaisseau = new Spatialship(screenW, screenH);
}

Spatialship *Game::GetVaisseau()
{
	return _vaisseau;
}

void Game::SetVaisseau(Spatialship * vso)
{
	_vaisseau = vso;
}

vector<Enemy*> Game::GetEnemyBoard()
{
	return _enemyBoard;
}

void Game::AddEnemyBoard(Enemy* ennemi)
{
	_enemyBoard.push_back(ennemi);
}

vector<Projectile*> Game::GetProjectileBoard()
{
	return _projectileBoard;
}

void Game::AddProjectileBoard(Projectile*  projectile)
{
	_projectileBoard.push_back(projectile);
}


// GESTION DU CLAVIER
void Game::KB_Management(float screenW)
{
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		if (_vaisseau->GetSprite().getPosition().x > 0.0) {
			_vaisseau->Vaisseau_Deplacement(LEFT);
		}
	}
	else if(Keyboard::isKeyPressed(Keyboard::Right)){
		if (_vaisseau->GetSprite().getPosition().x < screenW - (_vaisseau->GetTexture().getSize().x)) {
			_vaisseau->Vaisseau_Deplacement(RIGHT);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Space)) {
		if (_pTimeVaisseau.getElapsedTime().asMilliseconds() >= DELAY_MISSILE_VSO) {
			class Projectile *project = new Projectile(TEXTURE_PROJECTILE_SPATIALSHIP);
			project = project->Create_Projectile_Vaisseau(GetVaisseau(), project);
			AddProjectileBoard(project);
			_pTimeVaisseau.restart();
			cout << "TEST AJOUT MISSILE" << endl;
		}
	}
}

