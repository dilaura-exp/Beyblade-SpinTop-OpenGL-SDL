#pragma once
#include "GameObject.h"
#include "UI.h"

class SpinTop;

class SpinTopCollision : public Collision {
public:
	SpinTop *spinTop;
	Vector3 collidedVelocity;

	SpinTopCollision() {}
	SpinTopCollision(SpinTop *spinTop, Vector3 midPoint, Vector3 collidedPosition, float distance, Vector3 collidedVelocity) {
		this->spinTop = spinTop;
		this->midPoint = midPoint;
		this->collidedPosition = collidedPosition;
		this->distance = distance;
		this->collidedVelocity = collidedVelocity;
	}
	~SpinTopCollision() {}
};

class SpinTop : public GameObject{
private:
	float maxSpinSpeed;
	float spinSpeed;
	float spinDeceleration;
	float maxDirectionalSpeed;
	float directionalAcceleration;

	int leftInput, rightInput;
	int downInput, upInput;
	int horizontalInput;
	int verticalInput;
	float attackInput;

	Vector3 *directionalSpeed;
	void handleXMovement();
	void handleYMovement();
	void attack(SpinTopCollision *collision);

	float collisionRadius;

	float *material;
	int playerIndex;

public:
	SpinTop();
	~SpinTop();

	void init(float *material, int playerIndex);
	void update(float deltaTime);
	void draw();
	void input(SDL_Event &evnt);
	SpinTopCollision* checkCollision(SpinTop *spinTop);
	void onCollision(SpinTopCollision *collision);

	void setMaxSpinSpeed(float spinSpeed);
	void onDamage(float damage);
};

