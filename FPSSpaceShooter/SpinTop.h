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

public:
	SpinTop();
	~SpinTop();

	void init();
	void update(float deltaTime);
	void draw();
	void input(SDL_Event &evnt);

	void setSpinSpeed(float spinSpeed);
};

