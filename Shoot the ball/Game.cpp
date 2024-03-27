#include "Game.h"
#include <iostream>
#include <vector>

Game::Game() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "Fail to initialize SDL";
	}

	window = SDL_CreateWindow(
		"Shoot the ball",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		windowWidth,
		windowHeight,
		0
	);

	if (!window) {
		std::cout << "Failed to create window";
	}

	renderer = SDL_CreateRenderer(
		window,
		-1,
		SDL_RENDERER_ACCELERATED
	);

	if (!renderer) {
		std::cout << "Failed to create renderer";
	}

}

void Game::run() {
	bool running = true;
	SDL_Event event;

	int playerColor[4] = { 255, 255, 255, 255 };
	Player player(windowWidth / 2, windowHeight / 2, 10, playerColor);

	int projectileColor[4] = { 255, 255, 255, 255 };
	std::vector<Projectile> projectiles;

	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					int mouseX = event.button.x;
					int mouseY = event.button.y;

					double angleRadians = std::atan2(mouseY - windowHeight / 2, mouseX - windowWidth / 2);

					double velocityX = std::cos(angleRadians) / 2;
					double velocityY = std::sin(angleRadians) / 2;

					projectiles.emplace_back(windowWidth / 2, windowHeight / 2, 5, projectileColor, velocityX, velocityY);
				}
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		player.draw(renderer);

		for (Projectile& projectile : projectiles) {
			projectile.draw(renderer);
			projectile.update();
		}

		SDL_RenderPresent(renderer);
	}
}

void Game::cleanUp() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
