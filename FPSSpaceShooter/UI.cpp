#include "UI.h"
#include <iostream>

UI::UI() {
	/*if (instance != nullptr) {
		delete this;
	}
	else {
		instance = this;
	}*/
}

UI::~UI() {
}

UI &UI::getInstance() {
	static UI instance;
	return instance;
}

void UI::init() {

}

void UI::draw() {
	glPushMatrix();
		glClear(GL_DEPTH_BUFFER_BIT);
		glRotatef(-45, 1.0, 0, 0);
		getInstance().drawPlayer1HUD();
		getInstance().drawPlayer2HUD();
	glPopMatrix();
}

void UI::setMaxHealth(int playerIndex, float value) {
	getInstance().playerAttributes[playerIndex].maxHealth = value;
}

void UI::setHealth(int playerIndex, float value) {
	getInstance().playerAttributes[playerIndex].health = value;
}

void UI::drawPlayer1HUD() {
	float healthBarLength = 15.75f;
	glBegin(GL_QUADS);
		float materialBlack[]{ 0, 0, 0, 1 };
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, materialBlack);
		glVertex3f(-10.75, 6, 4.8);
		glVertex3f(5, 6, 4.8);
		glVertex3f(5, 5.5, 4.8);
		glVertex3f(-10.75, 5.5, 4.8);

		float materialWhite[]{ 1, 1, 1, 1.0 };
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, materialWhite);
		glVertex3f(-10.75, 6, 4.99);
		glVertex3f(5, 6, 4.99);
		glVertex3f(5, 5.5, 4.99);
		glVertex3f(-10.75, 5.5, 4.99);

		float materialRed[]{ 0.9, 0.4, 0.4, 1.0 };
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, materialRed);
		glVertex3f(-10.75, 6, 5);
		glVertex3f(-10.75 + healthBarLength*getInstance().playerAttributes[0].health / getInstance().playerAttributes[0].maxHealth, 6, 5);
		glVertex3f(-10.75 + healthBarLength*getInstance().playerAttributes[0].health / getInstance().playerAttributes[0].maxHealth, 5.5, 5);
		glVertex3f(-10.75, 5.5, 5);
	glEnd();
}

void UI::drawPlayer2HUD() {
	float healthBarLength = 15.75f;
		glBegin(GL_QUADS);
		float materialBlack[]{ 0, 0, 0, 1 };
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, materialBlack);
		glVertex3f(10.75, -6, 4.8);
		glVertex3f(-5, -6, 4.8);
		glVertex3f(-5, -5.5, 4.8);
		glVertex3f(10.75, -5.5, 4.8);

		float materialWhite[]{ 1, 1, 1, 1.0 };
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, materialWhite);
		glVertex3f(10.75, -6, 4.99);
		glVertex3f(-5, -6, 4.99);
		glVertex3f(-5, -5.5, 4.99);
		glVertex3f(10.75, -5.5, 4.99);

		float materialRed[]{ 0.4, 0.4, 0.9, 1.0 };
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, materialRed);
		glVertex3f(10.75, -6, 5);
		glVertex3f(10.75 - healthBarLength*getInstance().playerAttributes[1].health / getInstance().playerAttributes[1].maxHealth, -6, 5);
		glVertex3f(10.75 - healthBarLength*getInstance().playerAttributes[1].health / getInstance().playerAttributes[1].maxHealth, -5.5, 5);
		glVertex3f(10.75, -5.5, 5);
	glEnd();
}