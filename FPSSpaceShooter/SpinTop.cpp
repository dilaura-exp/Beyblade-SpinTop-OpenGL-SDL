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
	collisionRadius = 1.2f;

	this->playerIndex = playerIndex;
	if (playerIndex == 0) {
		position->x = -5.0f;
	}
	else if (playerIndex == 1) {
		position->x = 5.0f;
	}
	//rotation->z = -30;
}

void SpinTop::update(float deltaTime) {
	if (spinSpeed >= 0) {
		rotation->z = 30 - ((spinSpeed / maxSpinSpeed) * 30);
		rotation->y += spinSpeed * deltaTime;
		if (rotation->y > 360)
			rotation->y = 1;

		if (spinSpeed > 0) {
			spinSpeed -= spinDeceleration*deltaTime;
			if (spinSpeed < 0)
				spinSpeed = 0;
			spinDeceleration += 0.5 * deltaTime;
		}

		handleXMovement();
		handleYMovement();
		translate(*directionalSpeed * deltaTime * spinSpeed / 360.0f);

		if (attackInput > 0) {
			attackInput -= deltaTime;
		}
	}
}


void SpinTop::draw() {
	if (spinSpeed >= 0) {
		UI::setHealth(playerIndex, spinSpeed);
	}
	glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, material);
		glTranslatef(position->x, position->y, position->z);
		glRotatef(rotation->x, 1, 0, 0);
		glRotatef(rotation->y, 0, -1, 0);
		glRotatef(rotation->z, 0, 0, 1);
		glPushMatrix();
			glRotatef(2 * rotation->y, 0, 1, 0);
			glScalef(scale->x, scale->y, scale->z);
			glCallList(glListID);
		glPopMatrix();
	glPopMatrix();
}

void SpinTop::input(SDL_Event &evnt) {
	if (playerIndex == 0) {
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
			if (evnt.key.keysym.sym == SDLK_SPACE) {
				attackInput = 0.25f;
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
	else if (playerIndex == 1) {
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
			if (evnt.key.keysym.sym == SDLK_KP_0) {
				attackInput = true;
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
	horizontalInput = rightInput + leftInput;
	verticalInput = upInput + downInput;
}

void SpinTop::setMaxSpinSpeed(float spinSpeed) {
	this->maxSpinSpeed = spinSpeed;
	this->spinSpeed = spinSpeed;
	UI::setHealth(playerIndex, spinSpeed);
	UI::setMaxHealth(playerIndex, spinSpeed);
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

void SpinTop::attack(SpinTopCollision *collision) {
	collision->spinTop->onDamage(30);
	Vector3 attackDirection = *position - collision->collidedPosition;
	Vector3 *opponentSpeed = collision->spinTop->directionalSpeed;
	*opponentSpeed = attackDirection.getNormalized() * 10;
}

void SpinTop::onDamage(float damage) {
	spinSpeed -= damage;
}

SpinTopCollision* SpinTop::checkCollision(SpinTop *spinTop) {
	float xDif = position->x - spinTop->position->x;
	float yDif = position->y - spinTop->position->y;
	float zDif = position->z - spinTop->position->z;
	float distance = sqrt(pow(xDif, 2) + pow(yDif, 2) + pow(zDif, 2));
	if (distance <= collisionRadius + spinTop->collisionRadius) {
		Vector3 speedToSend(*spinTop->directionalSpeed);
		if (attackInput) {
			speedToSend = speedToSend * 2;
		}

		float midPointX = (position->x + spinTop->position->x) / 2;
		float midPointY = (position->y + spinTop->position->y) / 2;
		Vector3 midPoint(midPointX, midPointY, 0);

		SpinTopCollision *collision = new SpinTopCollision();
		collision->spinTop = spinTop;
		collision->midPoint = midPoint;
		collision->collidedPosition = *spinTop->position;
		collision->distance = distance;
		collision->collidedVelocity = speedToSend;

		return collision;
	}
	return nullptr;
}

void SpinTop::onCollision(SpinTopCollision *collision) {

	position->x = collision->midPoint.x + collisionRadius * (position->x - collision->collidedPosition.x) / collision->distance;
	position->y = collision->midPoint.y + collisionRadius * (position->y - collision->collidedPosition.y) / collision->distance;

	directionalSpeed = new Vector3(*directionalSpeed/-2 + collision->collidedVelocity/2);
	onDamage(5);

	if (attackInput > 0) {
		attackInput = 0;
		attack(collision);
	}
}