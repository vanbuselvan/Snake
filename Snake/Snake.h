#pragma once
#include <SDL.h>
#include "Board.h"
#include "Fruit.h"
#include <iostream>

class Snake : public Board {
protected:
	SDL_Rect * snake = new SDL_Rect[600];
private:
	int currentSize = 0;
	int x, y, w, h;
	int direction = 0;
public:
	void input();
	void draw();
	void updateHead();
	bool collideWithFruit(int x, int y);
	Snake(const Board &board, int _x, int _y, int _w, int _h);
	~Snake();
	bool snakeCollideWithSnake();
	inline int getCurrentSize() const { return currentSize; }
	inline int getDirection() const { return direction; }
	inline SDL_Rect getSnakePart(int index) { return snake[index]; }
};