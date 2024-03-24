#pragma once

#include <SDL.h>

class Game {
public:
	Game();
	void run();
	void cleanUp();

private:
	double windowWidth = 1200;
	double windowHeight = 680;
	SDL_Window* window;
	SDL_Renderer* renderer;
};