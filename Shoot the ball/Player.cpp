#include "Player.h"

Player::Player(double p_x, double p_y, double p_radius, int p_color[4]) {
	x = p_x;
	y = p_y;

	radius = p_radius;

	r = p_color[0];
	g = p_color[1];
	b = p_color[2];
	a = p_color[3];
}

void Player::draw(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, r, g, b, a);

	for (int dy = -radius; dy <= radius; dy++) {
		int width = sqrt(radius * radius - dy * dy) * 2;
		int startX = x - width / 2;
		int endX = startX + width;
		int currentY = y + dy;

		SDL_RenderDrawLine(renderer, startX, currentY, endX, currentY);
	}
}


