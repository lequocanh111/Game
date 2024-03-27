#pragma once
#include <SDL.h>

class Projectile
{
public:
	Projectile(double p_x, double p_y, double p_radius, int p_color[4], double p_velocityX, double velocityY);

	void draw(SDL_Renderer* renderer);
	void update();

private:
	double x, y;
	int radius;
	int r, g, b, a;
	double velocityX, velocityY;
};

