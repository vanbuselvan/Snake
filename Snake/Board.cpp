#include "Board.h"

Board::Board(const std::string title, int width, int height): name(title), windowWidth(width), windowHeight(height) {
	if (!init()) {
		quit = true;
	}
}

/*Board::Board() {
	windowWidth = 600;
	windowHeight = 400;
	name = "Snake";
}*/
bool Board::init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		return false;
	}

	gameWindow = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		windowWidth, windowHeight, 0);
	if (gameWindow == nullptr) {
		return false;
	}

	renderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		return false;
	}
	return true;
}

Board::~Board() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(gameWindow);
	SDL_Quit();
}

bool Board::isQuit() const{
	return quit;
}

void Board::pollEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			quit = true;
			break;
		default:
			break;
		}
	}
}

void Board::ShowScreen() {
	SDL_RenderPresent(renderer);
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 200, 255);
	SDL_RenderClear(renderer);
	
	
}
