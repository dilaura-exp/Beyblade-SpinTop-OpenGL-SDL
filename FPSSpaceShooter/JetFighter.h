#pragma once
#include "GameObject.h"

class JetFighter : public GameObject {
public:
	JetFighter();
	~JetFighter();

	void update(float deltaTime);
	void draw();
};

