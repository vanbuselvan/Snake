#pragma once
#include <SDL.h>
#include<iostream>

class Board {
private:
	SDL_Window * gameWindow = nullptr;
	int windowWidth, windowHeight;
	std::string name;
	bool quit = false;
protected:
	SDL_Renderer * renderer = nullptr;
public:
	Board(const std::string title, int width, int height);
	~Board();
private:
	bool init();
public:
	bool isQuit() const;
	void ShowScreen();
	inline void setQuitTrue() { quit = true; }
	void pollEvents();
};
