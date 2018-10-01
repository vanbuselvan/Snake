#include "Snake.h"

Snake::Snake(const Board &board, int _x, int _y, int _w, int _h) : Board(board), x(_x), y(_y), w(_w), h(_h) {

}

Snake::~Snake() {
	std::cout << "Memory free" << std::endl;
	delete[] snake;
}

void Snake::draw() {
	for (int i = currentSize; i > 0; i--) {
		snake[i].x = snake[i - 1].x;
		snake[i].y = snake[i - 1].y;
	}
	updateHead();
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	SDL_RenderFillRects(renderer, snake, currentSize + 1);
}

void Snake::updateHead() {
	switch (direction) {
	case 0:
		snake[0].x = x;
		snake[0].y = y;
		snake[0].w = w;
		snake[0].h = h;
	case 1:
		snake[0].x = snake[0].x + w;
		if (snake[0].x > 600)
			snake[0].x = 0;
		break;
	case 2:
		snake[0].x = snake[0].x - w;
		if (snake[0].x < 0)
			snake[0].x = 600;
		break;
	case 3:
		snake[0].y = snake[0].y - h;
		if (snake[0].y < 0)
			snake[0].y = 400;
		break;
	case 4:
		snake[0].y = snake[0].y + h;
		if (snake[0].y > 400)
			snake[0].y = 0;
		break;
	}
}

void Snake::input() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.key.keysym.sym) {
		case SDLK_RIGHT:
			direction = 1;
			break;
		case SDLK_LEFT:
			direction = 2;
			break;
		case SDLK_UP:
			direction = 3;
			break;
		case SDLK_DOWN:
			direction = 4;
			break;
		default:
			break;
		}
	}
}

bool Snake::collideWithFruit(int x, int y) {
	SDL_Rect *a = new SDL_Rect;
	a->h = 20;
	a->w = 20;
	a->x = x;
	a->y = y;
	if (SDL_HasIntersection(&snake[0], a)) {
		currentSize++;
		snake[currentSize].x = snake[currentSize - 1].x + w;
		snake[currentSize].y = snake[currentSize - 1].y;
		snake[currentSize].w = w;
		snake[currentSize].h = h;
		delete a;
		return true;
	}
	delete a;
	return false;
}

bool Snake::snakeCollideWithSnake() {
	for (int i = 1; i < currentSize; i++) {
		if (SDL_HasIntersection(&snake[0], &snake[i])) {
			return true;
		}
	}
	return false;
}