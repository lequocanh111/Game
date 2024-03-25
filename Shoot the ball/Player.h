#pragma once
#include <SDL.h>

class Player
{
public:
	Player(double p_x, double p_y, double p_radius, int p_color[4]);

	void draw(SDL_Renderer* renderer);

private:
	double x, y;
	int radius;
	int r, g, b, a;
};

