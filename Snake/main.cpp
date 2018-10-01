#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Board.h"
#include "Fruit.h"
#include "Snake.h"

int main(int, char**) {
	Board board = Board("Snake", 600, 400);
	Fruit fruit = Fruit(board, 300, 200, 20, 20);
	Snake snake = Snake(board, 200, 200, 20, 20);
	while (!board.isQuit()) {
		SDL_Delay(70);
		fruit.spawnFruit();
		snake.input();
		snake.draw();
		if (snake.collideWithFruit(fruit.getX(), fruit.getY())) {
			fruit.generateCoordinates();
		}
		if (snake.snakeCollideWithSnake()) {
			board.setQuitTrue();
		}
		board.pollEvents();
		board.ShowScreen();
	}
	return 0;
}