#pragma once
#include <SDL.h>
#include "Board.h"
#include <iostream>
#include "Snake.h"

class Fruit : public Board {
private:
	SDL_Rect fruit;
	int x, y, w, h;
public:
	Fruit(const Board &board, int _x, int _y, int _w, int _h);
	void spawnFruit();
	inline SDL_Rect getFruit() const { return fruit; } 
	inline int getX() const { return x; }
	inline int getY() const { return y; }
	void generateCoordinates();
	void generateNewCoordinates(SDL_Rect snakePart);
};