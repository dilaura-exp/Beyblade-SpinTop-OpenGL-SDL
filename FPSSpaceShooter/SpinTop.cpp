#include "SpinTop.h"
#include "ObjectLoader.h"
#include <iostream>
#include <math.h>


SpinTop::SpinTop() {
	directionalSpeed = new Vector3();
	maxDirectionalSpeed = 5.0f;
	directionalAcceleration = 0.02f;
}


SpinTop::~SpinTop() {
}

void SpinTop::init() {
	material[0] = 0.75f;
	material[1] = 0.25f;
	material[2] = 0.23f;
	material[3] = 1.0f;

	glListID = ObjectLoader::loadWavefront("simplebeyblade.obj");
	spinSpeed = 0.0f;
}

void SpinTop::update(float deltaTime) {
	rotation->y += spinSpeed * deltaTime;
	if (rotation->y > 360)
		rotation->y = 1;

	if (spinSpeed > 0) {
		spinSpeed -= spinDeceleration*deltaTime;
		if (spinSpeed < 0)
			spinSpeed = 0;
		spinDeceleration += 0.5 * deltaTime;
	}

	if (horizontalInput != 0) {
		if (abs(directionalSpeed->x) < maxDirectionalSpeed) {
			directionalSpeed->x += directionalAcceleration*horizontalInput;
		}
	}
	else {
		if (directionalSpeed->x > 0) {
			directionalSpeed->x -= directionalAcceleration*horizontalInput;
		}
		else if (directionalSpeed->x < 0) {
			directionalSpeed->x += directionalAcceleration*horizontalInput;
		}
	}

	translate(*directionalSpeed);
}

void SpinTop::draw() {
	glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, material);
		glTranslatef(position->x, position->y, position->z);
		glRotatef(rotation->x, 1.0, 0, 0);
		glRotatef(rotation->y, 0.0, 1.0, 0);
		glRotatef(rotation->z, 0.0, 0.0, 1.0);
		glScalef(scale->x, scale->y, scale->z);
		glCallList(glListID);
	glPopMatrix();
}

void SpinTop::input(SDL_Event &evnt) {
	if (evnt.type == SDL_KEYDOWN) {
		if (evnt.key.keysym.sym == SDLK_LEFT) {
			leftInput = -1;
		}
		if (evnt.key.keysym.sym == SDLK_RIGHT) {
			rightInput = 1;
		}
		if (evnt.key.keysym.sym == SDLK_UP) {
			upInput = 1;
		}
		if (evnt.key.keysym.sym == SDLK_DOWN) {
			downInput = -1;
		}
	}
	if (evnt.type == SDL_KEYUP) {
		if (evnt.key.keysym.sym == SDLK_LEFT) {
			leftInput = 0;
		}
		if (evnt.key.keysym.sym == SDLK_RIGHT) {
			rightInput = 0;
		}
		if (evnt.key.keysym.sym == SDLK_UP) {
			upInput = 0;
		}
		if (evnt.key.keysym.sym == SDLK_DOWN) {
			downInput = 0;
		}
	}
	horizontalInput = rightInput + leftInput;
	verticalInput = upInput + downInput;
}

void SpinTop::setSpinSpeed(float spinSpeed) {
	this->spinSpeed = spinSpeed;
}