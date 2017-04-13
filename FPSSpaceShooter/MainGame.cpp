#include "MainGame.h"
#include "ErrorLog.h"
#include "ImageLoader.h"
#include "ObjectLoader.h"
#include "GLTexture.h"

#include <iostream>
#include <vector>

MainGame::MainGame() {
	screenWidth = 1366;
	screenHeight = 768;
	window = nullptr;
	gameState = GameState::PLAY;
	currentTime = SDL_GetTicks();
	deltaTime = 0;
}

MainGame::~MainGame() {
}

void MainGame::run() {
	initSystems();

	gameLoop();
}

GLTexture texture;

void MainGame::initSystems() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("FPS Space Shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);
	if (window == nullptr) {
		logFatalError("SDL Window could not be created.");
	}
	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	if (glContext == nullptr) {
		logFatalError("SDL GL Context could not be created.");
	}
	GLenum glStatus = glewInit();
	if (glStatus != GLEW_OK) {
		logFatalError("glew could not be initialized.");
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1366.0 / 768.0, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);		
	glEnable(GL_FOG);
	glFogi(GL_FOG_MODE, GL_LINEAR);
	//glFogi(GL_FOG_DENSITY, 0.3f);
	glFogf(GL_FOG_START, 1.0);
	glFogf(GL_FOG_END, 10.0);
	float color[] = { 0.5, 0.5, 0.5, 1.0 };
	glFogfv(GL_FOG_COLOR, color);
	//glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);
	texture = ImageLoader::loadPNG("brick3.png");
	float dif[] = {1.0, 1.0, 1.0, 1.0};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
	float amb[] = { 0.2, 0.2, 0.2, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
	
}

void MainGame::gameLoop() {
	while (gameState != GameState::EXIT) {
		oldTime = currentTime;
		currentTime = SDL_GetTicks();
		deltaTime = (currentTime - oldTime) / 1000.0f;

		processInput();
		drawGame();
	}
}

void MainGame::processInput() {
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
			case SDL_QUIT:
				gameState = GameState::EXIT;
				break;
			case SDL_MOUSEMOTION:
				break;
			case SDL_KEYDOWN:
				break;
			case SDL_MOUSEBUTTONDOWN:
				break;
		}
	}
}

float angle = 0.0f;
int cube;

void MainGame::drawGame() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	float pos[] = { -2.0, 2.0, -3.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	//std::cout << deltaTime << std::endl;
	angle += (30.0f*deltaTime);
	if (angle >= 360.0f) angle = 0.0f;
	/*
	glBindTexture(GL_TEXTURE_2D, texture.id);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(-2.0, 2.0, 0.0);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(-2.0, -2.0, 0.0);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(2.0, -2.0, 0.0);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(2.0, 2.0, 0.0);
	glEnd();*/

	cube = ObjectLoader::loadWavefront("monkey.obj");
	glPushMatrix();
		glTranslatef(-2.0, 0.0, -10.0);
		glRotatef(angle, 1.0, 1.0, 1.0);
		glCallList(cube);
	glPopMatrix();
	glTranslatef(2.0, 0.0, -8.0);
	glRotatef(-angle, 1.0, 1.0, 1.0);
	glCallList(cube);

	SDL_GL_SwapWindow(window);
}

void drawTriangleList() {
	int triangle = 1;
	glNewList(triangle, GL_COMPILE);
		glBegin(GL_TRIANGLES);
			glColor3f(1.0, 0.0, 0.0);
			glVertex3f(0.0, 2.0, -5.0);
			glColor3f(0.0, 1.0, 0.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(2.0, -2.0, -5.0);
		glEnd();
	glEndList();

	glCallList(triangle);
}

void drawCube(float size) {
	float ambdif[] = {1.0, 0.5, 0.3, 1.0};
	glBegin(GL_QUADS);
		//front
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, ambdif);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(size / 2, size / 2, size / 2);
		glVertex3f(-size / 2, size / 2, size / 2);
		glVertex3f(-size / 2, -size / 2, size / 2);
		glVertex3f(size / 2, -size / 2, size / 2);

		//left
		glNormal3f(-1.0, 0.0, 0.0);
		glVertex3f(-size / 2, size / 2, size / 2);
		glVertex3f(-size / 2, size / 2, -size / 2);
		glVertex3f(-size / 2, -size / 2, -size / 2);
		glVertex3f(-size / 2, -size / 2, size / 2);

		//back
		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(-size / 2, size / 2, -size / 2);
		glVertex3f(size / 2, size / 2, -size / 2);
		glVertex3f(size / 2, -size / 2, -size / 2);
		glVertex3f(-size / 2, -size / 2, -size / 2);

		//right
		glNormal3f(1.0, 0.0, 0.0);
		glVertex3f(size / 2, size / 2, size / 2);
		glVertex3f(size / 2, size / 2, -size / 2);
		glVertex3f(size / 2, -size / 2, -size / 2);
		glVertex3f(size / 2, -size / 2, size / 2);

		//top
		glNormal3f(0.0, 1.0, 0.0);
		glVertex3f(size / 2, size / 2, size / 2);
		glVertex3f(-size / 2, size / 2, size / 2);
		glVertex3f(-size / 2, size / 2, -size / 2);
		glVertex3f(size / 2, size / 2, -size / 2);

		//bottom
		glNormal3f(0.0, -1.0, 0.0);
		glVertex3f(size / 2, -size / 2, size / 2);
		glVertex3f(-size / 2, -size / 2, size / 2);
		glVertex3f(-size / 2, -size / 2, -size / 2);
		glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();
}