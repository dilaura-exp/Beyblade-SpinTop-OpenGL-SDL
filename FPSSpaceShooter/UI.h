#pragma once
#include <GL\glew.h>

class PlayerAttributes {
public:
	float health;
	float maxHealth;
};

class UI {
public:
	~UI();

	static UI &getInstance();
	static void init();
	static void draw();
	static void setMaxHealth(int playerIndex, float value);
	static void setHealth(int playerIndex, float value);

private:
	UI();

	PlayerAttributes playerAttributes[2];
	void drawPlayer1HUD();
	void drawPlayer2HUD();
};

