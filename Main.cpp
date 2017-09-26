#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.h"
#include "Enumeration.h"

using namespace sf;
using namespace std;


Clock DeplacementEnemy;

RenderWindow window;


int main(int argc, char *argv[]) {
	srand(time(NULL));
	// DECLARATION DE LA FENETRE & LIMITATION DES FPS A 60
	window.create(VideoMode(screenW, screenH), "SHMUP");
	window.setFramerateLimit(60);

	// DECLARATION DE GAME
	class Game game(screenW, screenH);
	int level = 1;

	game.AddEnemyLevelBoard(1, enemyLevelOneBoard);
	game.AddEnemyLevelBoard(2, enemyLevelTwoBoard);
	game.AddEnemyLevelBoard(3, enemyLevelTreeBoard);

	/* -- BOUCLE PRINCIPAL -- */
	while (window.isOpen()) {
		Event event;

		// GESTION DES EVENTS
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		game.KB_Management(screenW);


		if (DeplacementEnemy.getElapsedTime().asMilliseconds() >= 100) {
			game.Enemy_Management(screenH, level);
			DeplacementEnemy.restart();
		}
		game.Projectile_Management();
		game.Explosion_Management();

		game.Collision();

		if ((game.GetEnemyBoard().size() < 1) && (game.GetIndexBoardEnemyLevel() == game.GetSizeEnemyLevelBoard(level))){
			game.GetEnemyBoard().clear();
			level++; 
			cout << "LEVEL " << level << endl;
		}
		// GESTION D'AFFICHAGE
			// DESSINE LES PROJECTILES
		auto projectileBoard = game.GetProjectileBoard();
		for (vector<Projectile *>::iterator it = projectileBoard.begin();
			it < projectileBoard.end();
			it++) {
			window.draw((*it)->GetSprite());
		}
			// DESSINE LE VAISSEAU
		window.draw(game.GetVaisseau()->GetSprite());
			// DESSINE LES ENEMIES
		auto enemyBoard = game.GetEnemyBoard();
		for (vector<Enemy *>::iterator it = enemyBoard.begin();
			it < enemyBoard.end();
			it++) {
			window.draw((*it)->GetSprite());
		}
			// DESSINE LES EXPLOSIONS
		auto explosionBoard = game.GetExplosionBoard();
		for (vector<Explosion *>::iterator it = explosionBoard.begin();
			it < explosionBoard.end();
			it++) {
			window.draw((*it)->GetSprite());
		}

		window.display();
		window.clear();
	}
	return EXIT_SUCCESS;
}

