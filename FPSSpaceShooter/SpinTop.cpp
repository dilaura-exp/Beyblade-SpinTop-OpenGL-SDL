#include "SpinTop.h"
#include "ObjectLoader.h"
#include <iostream>
#include <math.h>


SpinTop::SpinTop() {
	directionalSpeed = new Vector3();
}

SpinTop::~SpinTop() {
}


void SpinTop::init(float *material, int playerIndex) {
	this->material = material;

	glListID = ObjectLoader::loadWavefront("simplebeyblade.obj");
	spinSpeed = 0.0f;
	maxDirectionalSpeed = 5.0f;
	directionalAcceleration = 0.075f;
	collisionRadius = 1.36511f;

	this->playerIndex = playerIndex;
	if (playerIndex == 0) {
		position->x = -5.0f;
	}
	else if (playerIndex == 1) {
		position->x = 5.0f;
	}
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

	if (spinSpeed > 0) {
		handleXMovement();
		handleYMovement();
		translate(*directionalSpeed * deltaTime * spinSpeed / 360.0f);
	}
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
	if (playerIndex == 0) {
		if (evnt.type == SDL_KEYDOWN) {
			if (evnt.key.keysym.sym == SDLK_LEFT) {
				leftInput = -1;
			}
			if (evnt.key.keysym.sym == SDLK_RIGHT) {
				rightInput = 1;
			}
			if (evnt.key.keysym.sym == SDLK_UP) {
				upInput = -1;
			}
			if (evnt.key.keysym.sym == SDLK_DOWN) {
				downInput = 1;
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
	}
	else if (playerIndex == 1) {
		if (evnt.type == SDL_KEYDOWN) {
			if (evnt.key.keysym.sym == SDLK_a) {
				leftInput = -1;
			}
			if (evnt.key.keysym.sym == SDLK_d) {
				rightInput = 1;
			}
			if (evnt.key.keysym.sym == SDLK_w) {
				upInput = -1;
			}
			if (evnt.key.keysym.sym == SDLK_s) {
				downInput = 1;
			}
		}
		if (evnt.type == SDL_KEYUP) {
			if (evnt.key.keysym.sym == SDLK_a) {
				leftInput = 0;
			}
			if (evnt.key.keysym.sym == SDLK_d) {
				rightInput = 0;
			}
			if (evnt.key.keysym.sym == SDLK_w) {
				upInput = 0;
			}
			if (evnt.key.keysym.sym == SDLK_s) {
				downInput = 0;
			}
		}
	}
	horizontalInput = rightInput + leftInput;
	verticalInput = upInput + downInput;
}

void SpinTop::setSpinSpeed(float spinSpeed) {
	this->spinSpeed = spinSpeed;
}

void SpinTop::handleXMovement() {
	if (horizontalInput != 0) {
		if (abs(directionalSpeed->x) < maxDirectionalSpeed) {
			directionalSpeed->x += directionalAcceleration*horizontalInput;
		}
	}
	else {
		if (directionalSpeed->x > 0) {
			directionalSpeed->x -= directionalAcceleration;
		}
		else if (directionalSpeed->x < 0) {
			directionalSpeed->x += directionalAcceleration;
		}
	}
}

void SpinTop::handleYMovement() {
	if (verticalInput != 0) {
		if (abs(directionalSpeed->z) < maxDirectionalSpeed) {
			directionalSpeed->z += directionalAcceleration*verticalInput;
		}
	}
	else {
		if (directionalSpeed->z > 0) {
			directionalSpeed->z -= directionalAcceleration;
		}
		else if (directionalSpeed->z < 0) {
			directionalSpeed->z += directionalAcceleration;
		}
	}
}

bool SpinTop::checkCollision(SpinTop *spinTop) {
	float xDif = position->x - spinTop->position->x;
	float yDif = position->y - spinTop->position->y;
	float zDif = position->z - spinTop->position->z;
	float distance = sqrt(pow(xDif, 2) + pow(yDif, 2) + pow(zDif, 2));
	if (distance <= collisionRadius + spinTop->collisionRadius) {
		Vector3 newSpeed = (directionalSpeed->getAbsolute() + spinTop->directionalSpeed->getAbsolute()) / 2;
		Vector3 sign = directionalSpeed->getSign();

		directionalSpeed = new Vector3(newSpeed.x * -sign.x, newSpeed.y * -sign.y, newSpeed.z * -sign.z);
		spinTop->directionalSpeed = new Vector3(newSpeed.x * sign.x, newSpeed.y * sign.y, newSpeed.z * sign.z);
	}
	return false;
}