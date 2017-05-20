#pragma once
#include "GameObject.h"

class SpinTop : public GameObject{
private:
	float spinSpeed;
	float spinDeceleration;
	float maxDirectionalSpeed;
	float directionalAcceleration;

	int leftInput, rightInput;
	int downInput, upInput;
	int horizontalInput;
	int verticalInput;

	Vector3 *directionalSpeed;
	void handleXMovement();
	void handleYMovement();

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
	bool checkCollision(SpinTop *spinTop);

	void setSpinSpeed(float spinSpeed);
};

