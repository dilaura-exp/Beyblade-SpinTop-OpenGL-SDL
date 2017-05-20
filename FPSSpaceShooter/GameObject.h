#pragma once
#include <GL/glew.h>
#include <SDL/SDL.h>
#include <cmath>

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

	Vector3 operator * (const float multiplier) {
		Vector3 newVector(x, y, z);
		newVector.x *= multiplier;
		newVector.y *= multiplier;
		newVector.z *= multiplier;
		return newVector;
	}
	Vector3 operator / (const float multiplier) {
		Vector3 newVector(x, y, z);
		newVector.x /= multiplier;
		newVector.y /= multiplier;
		newVector.z /= multiplier;
		return newVector;
	}
	Vector3 operator + (const Vector3 &vectorb) {
		Vector3 result;
		result.x = x + vectorb.x;
		result.y = y + vectorb.y;
		result.z = z + vectorb.z;
		return result;
	}
	Vector3 operator - (const Vector3 &vectorb) {
		Vector3 result;
		result.x = x - vectorb.x;
		result.y = y - vectorb.y;
		result.z = z - vectorb.z;
		return result;
	}
	Vector3 getAbsolute() {
		Vector3 result;
		result.x = abs(x);
		result.y = abs(y);
		result.z = abs(z);
		return result;
	}
	Vector3 getSign() {
		Vector3 result(0, 0, 0);
		if (x > 0)
			result.x = 1;
		else if (x < 0)
			result.x = -1;
		if (y > 0)
			result.y = 1;
		else if (y < 0)
			result.y = -1;
		if (z > 0)
			result.z = 1;
		else if (z < 0)
			result.z = -1;
		return result;
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

