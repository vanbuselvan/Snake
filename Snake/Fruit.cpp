#include "Fruit.h"

Fruit::Fruit(const Board &board, int _x, int _y, int _w, int _h) : Board(board), x(_x), y(_y), w(_w), h(_h) {
	
}

void Fruit::spawnFruit() {
	fruit.w = w;
	fruit.h = h;
	fruit.x = x;
	fruit.y = y;
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &fruit);
}

void Fruit::generateCoordinates() {
	x = (rand() % 30)*w;
	y = (rand() % 20)*h;
	fruit.x = x;
	fruit.y = y;
}

void Fruit::generateNewCoordinates(SDL_Rect snakePart) {
	if (SDL_HasIntersection(&fruit, &snakePart)) {
		x = (rand() % 30)*w;
		y = (rand() % 20)*h;
		fruit.x = x;
		fruit.y = y;
	}
}