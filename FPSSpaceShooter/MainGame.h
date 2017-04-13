#pragma once

#include <SDL/SDL.h>
#include <SDL_image.h>
#include <GL/glew.h>

#include "IOManager.h"

enum class GameState{PLAY, EXIT};

class MainGame {
public:
	MainGame();
	~MainGame();

	void run();

private:
	SDL_Window* window;
	int screenWidth;
	int screenHeight;
	GameState gameState;

	Uint32 oldTime, currentTime;
	float deltaTime;

	void initSystems();
	void gameLoop();
	void processInput();
	void drawGame();
};

