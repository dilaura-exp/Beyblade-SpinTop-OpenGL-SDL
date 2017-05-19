#pragma once
#include <GL/glew.h>
#include <SDL/SDL.h>

struct Vector3 {
	float x, y, z;

	Vector3() {
		x = y = z = 0.0f;
	}

	Vector3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void set(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

class GameObject {
protected:
	int glListID;
	float material[4];

public:
	GameObject();
	~GameObject();

	Vector3 *position;
	Vector3 *rotation;
	Vector3 *scale;

	virtual void init();
	virtual void update(float deltaTime);
	virtual void draw();
	virtual void input(SDL_Event &evnt);

	void translate(const Vector3 &translation);
};

