#include "Game.h"
#include <iostream>

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
	
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);
	}
}

void Game::cleanUp() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
