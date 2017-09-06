#include <SFML\Graphics.hpp>
#include <iostream>

#include "Game.h"

using namespace sf;
using namespace std;

#pragma region Constantes
const float screenW = 800.0;
const float screenH = 600.0;
const int DELAY_MISSILE_VSO = 300;
#pragma endregion Constantes

RenderWindow window;

#pragma region Prototypes
#pragma endregion Prototypes

int main(int argc, char *argv[]) {
	// DECLARATION DE LA FENETRE & LIMITATION DES FPS A 60
	window.create(VideoMode(screenW, screenH), "SHMUP");
	window.setFramerateLimit(60);

	// DECLARATION DE GAME
	class Game game(screenW, screenH);

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

		// GESTION D'AFFICHAGE
			// DESSINE LE VAISSEAU
		window.draw(game.GetVaisseau()->GetSprite());

			// DESSINE LES PROJECTILES
		/*for (vector<Projectile*>::iterator it = game.GetProjectileBoard().begin();
			it < game.GetProjectileBoard().end();
			it++) {
			window.draw((*it)->GetSprite());
		}*/

		window.display();
		window.clear();
	}
	return EXIT_SUCCESS;
}
