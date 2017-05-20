#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>

#include "IOManager.h"
#include "SpinTop.h"

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
	
	SpinTop *playerSpinTop;
	SpinTop *cpuSpinTop;

	void initSystems();
	void initGameObjects();
	void gameLoop();
	void processInput();
	void drawGame();
};

