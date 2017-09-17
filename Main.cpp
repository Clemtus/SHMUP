#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.h"

using namespace sf;
using namespace std;


const float screenW = 800.0;
const float screenH = 600.0;

Clock DeplacementEnemey;

RenderWindow window;


int main(int argc, char *argv[]) {
	srand(time(NULL));
	// DECLARATION DE LA FENETRE & LIMITATION DES FPS A 60
	window.create(VideoMode(screenW, screenH), "SHMUP");
	window.setFramerateLimit(60);

	// DECLARATION DE GAME
	class Game game(screenW, screenH);
	bool enemy = true;

	/* -- BOUCLE PRINCIPAL -- */
	while (window.isOpen()) {
		Event event;

		// GESTION DES EVENTS
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		if (enemy) {
			game.Enemy_Generation(screenW, 1);
			cout << game.GetNbEnemy() << endl;
			enemy = false;
		}
		
		game.KB_Management(screenW);
		
		
		if (DeplacementEnemey.getElapsedTime().asMilliseconds() >= 150) {
			game.Enemy_Management(screenH);
			DeplacementEnemey.restart();
		}
		game.Projectile_Management();
		game.Explosion_Management();

		game.Collision();


		// GESTION D'AFFICHAGE
			// DESSINE LES PROJECTILES
		auto projectileBoard = game.GetProjectileBoard();
		for (vector<Projectile>::iterator it = projectileBoard.begin();
			it < projectileBoard.end();
			it++) {
			window.draw(it->GetSprite());
		}
			// DESSINE LE VAISSEAU
		window.draw(game.GetVaisseau()->GetSprite());
			// DESSINE LES ENEMIES
		auto enemyBoard = game.GetEnemyBoard();
		for (vector<Enemy>::iterator it = enemyBoard.begin();
			it < enemyBoard.end();
			it++) {
			window.draw(it->GetSprite());
		}
			// DESSINE LES EXPLOSIONS
		auto explosionBoard = game.GetExplosionBoard();
		for (vector<Explosion>::iterator it = explosionBoard.begin();
			it < explosionBoard.end();
			it++) {
			window.draw(it->GetSprite());
		}

		window.display();
		window.clear();
	}
	return EXIT_SUCCESS;
}

