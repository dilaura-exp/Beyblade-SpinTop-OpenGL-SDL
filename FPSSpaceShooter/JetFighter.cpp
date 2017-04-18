#include "JetFighter.h"



JetFighter::JetFighter() {
	position = new Vector3(0, 0, 0);
	rotation = new Vector3(0, 0, 0);
	scale = new Vector3(1, 1, 1);
}


JetFighter::~JetFighter() {
}

void JetFighter::update(float deltaTime) {

}

void JetFighter::draw() {
	glBegin(GL_QUADS);
		float ambdif[] = { 0.05, 0.05, 0.5, 1.0 };
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, ambdif);

		glVertex3f(position->x, position->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 1 * scale->x, position->y -1 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 1 * scale->x, position->y -1 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x, position->y, position->z - 1 * scale->z);

		glVertex3f(position->x + 1 * scale->x, position->y -1 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 1 * scale->x, position->y -4 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 1 * scale->x, position->y -4 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 1 * scale->x, position->y -1 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x + 1 * scale->x, position->y -4 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y -6 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y -6 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 1 * scale->x, position->y -4 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x + 3 * scale->x, position->y -6 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y -9 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y -9 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y -6 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x + 3 * scale->x, position->y -9 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 8 * scale->x, position->y -13 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 8 * scale->x, position->y -13 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y -9 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x + 8 * scale->x, position->y -13 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 8 * scale->x, position->y -15 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 8 * scale->x, position->y -15 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 8 * scale->x, position->y -13 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x + 8 * scale->x, position->y -15 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y -16 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y -16 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 8 * scale->x, position->y -15 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x + 3 * scale->x, position->y -16 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 5 * scale->x, position->y -19 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 5 * scale->x, position->y -19 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y -16 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x + 5 * scale->x, position->y -19 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 4 * scale->x, position->y -21 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 4 * scale->x, position->y -21 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 5 * scale->x, position->y -19 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x + 4 * scale->x, position->y -21 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x, position->y - 19 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x, position->y - 19 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 4 * scale->x, -21 * scale->y, position->z - 1 * scale->z);

		//mirror side
		glVertex3f(position->x, position->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 1 * scale->x, position->y - 1 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 1 * scale->x, position->y - 1 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x, position->y, position->z - 1 * scale->z);

		glVertex3f(position->x - 1 * scale->x, position->y - 1 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 1 * scale->x, position->y - 4 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 1 * scale->x, position->y - 4 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x - 1 * scale->x, position->y - 1 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x - 1 * scale->x, position->y - 4 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 3 * scale->x, position->y - 6 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 3 * scale->x, position->y - 6 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x - 1 * scale->x, position->y - 4 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x - 3 * scale->x, position->y - 6 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 3 * scale->x, position->y - 9 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 3 * scale->x, position->y - 9 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x - 3 * scale->x, position->y - 6 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x - 3 * scale->x, position->y - 9 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 8 * scale->x, position->y - 13 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 8 * scale->x, position->y - 13 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x - 3 * scale->x, position->y - 9 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x - 8 * scale->x, position->y - 13 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 8 * scale->x, position->y - 15 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 8 * scale->x, position->y - 15 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x - 8 * scale->x, position->y - 13 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x - 8 * scale->x, position->y - 15 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 3 * scale->x, position->y - 16 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 3 * scale->x, position->y - 16 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x - 8 * scale->x, position->y - 15 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x - 3 * scale->x, position->y - 16 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 5 * scale->x, position->y - 19 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 5 * scale->x, position->y - 19 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x - 3 * scale->x, position->y - 16 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x - 5 * scale->x, position->y - 19 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 4 * scale->x, position->y - 21 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 4 * scale->x, position->y - 21 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x - 5 * scale->x, position->y - 19 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x - 4 * scale->x, position->y - 21 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x, position->y - 19 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x, position->y - 19 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x - 4 * scale->x, -21 * scale->y, position->z - 1 * scale->z);

		ambdif[0] = 0.05; ambdif[1] = 0.05f;
		ambdif[2] = 0.75; ambdif[3] = 1.0;
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, ambdif);

		//up
		glVertex3f(position->x - 1 * scale->x, position->y - 1 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 1 * scale->x, position->y - 1 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 1 * scale->x, position->y - 4 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 1 * scale->x, position->y - 4 * scale->y, position->z + 1 * scale->z);

		glVertex3f(position->x - 1 * scale->x, position->y - 4 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 1 * scale->x, position->y - 4 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y - 6 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 3 * scale->x, position->y - 6 * scale->y, position->z + 1 * scale->z);

		glVertex3f(position->x - 3 * scale->x, position->y - 6 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y - 6 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y - 9 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 3 * scale->x, position->y - 9 * scale->y, position->z + 1 * scale->z);

		glVertex3f(position->x - 3 * scale->x, position->y - 9 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y - 9 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 8 * scale->x, position->y - 13 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 8 * scale->x, position->y - 13 * scale->y, position->z + 1 * scale->z);

		glVertex3f(position->x - 8 * scale->x, position->y - 13 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 8 * scale->x, position->y - 13 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 8 * scale->x, position->y - 15 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 8 * scale->x, position->y - 15 * scale->y, position->z + 1 * scale->z);

		glVertex3f(position->x - 8 * scale->x, position->y - 15 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 8 * scale->x, position->y - 15 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y - 16 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 3 * scale->x, position->y - 16 * scale->y, position->z + 1 * scale->z);

		glVertex3f(position->x - 3 * scale->x, position->y - 16 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y - 16 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 5 * scale->x, position->y - 19 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 5 * scale->x, position->y - 19 * scale->y, position->z + 1 * scale->z);

		glVertex3f(position->x - 1 * scale->x, position->y - 4 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 1 * scale->x, position->y - 4 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y - 6 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 3 * scale->x, position->y - 6 * scale->y, position->z + 1 * scale->z);

		//below
		glVertex3f(position->x - 1 * scale->x, position->y - 1 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 1 * scale->x, position->y - 1 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 1 * scale->x, position->y - 4 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x - 1 * scale->x, position->y - 4 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x - 1 * scale->x, position->y - 4 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 1 * scale->x, position->y - 4 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y - 6 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x - 3 * scale->x, position->y - 6 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x - 3 * scale->x, position->y - 6 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y - 6 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y - 9 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x - 3 * scale->x, position->y - 9 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x - 3 * scale->x, position->y - 9 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y - 9 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 8 * scale->x, position->y - 13 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x - 8 * scale->x, position->y - 13 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x - 8 * scale->x, position->y - 13 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 8 * scale->x, position->y - 13 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 8 * scale->x, position->y - 15 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x - 8 * scale->x, position->y - 15 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x - 8 * scale->x, position->y - 15 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 8 * scale->x, position->y - 15 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y - 16 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x - 3 * scale->x, position->y - 16 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x - 3 * scale->x, position->y - 16 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y - 16 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 5 * scale->x, position->y - 19 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x - 5 * scale->x, position->y - 19 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x - 1 * scale->x, position->y - 4 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 1 * scale->x, position->y - 4 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 3 * scale->x, position->y - 6 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x - 3 * scale->x, position->y - 6 * scale->y, position->z - 1 * scale->z);
	glEnd();

	glBegin(GL_TRIANGLES);
		//up
		glVertex3f(position->x, position->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 1 * scale->x, position->y - 1 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 1 * scale->x, position->y - 1 * scale->y, position->z + 1 * scale->z);

		glVertex3f(position->x - 5 * scale->x, position->y - 19 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x, position->y - 19 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x - 4 * scale->x, position->y - 21 * scale->y, position->z + 1 * scale->z);

		glVertex3f(position->x, position->y - 19 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 5 * scale->x, position->y - 19 * scale->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 4 * scale->x, position->y - 21 * scale->y, position->z + 1 * scale->z);

		//below
		glVertex3f(position->x, position->y, position->z + 1 * scale->z);
		glVertex3f(position->x + 1 * scale->x, position->y - 1 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x - 1 * scale->x, position->y - 1 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x - 5 * scale->x, position->y - 19 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x, position->y - 19 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x - 4 * scale->x, position->y - 21 * scale->y, position->z - 1 * scale->z);

		glVertex3f(position->x, position->y - 19 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 5 * scale->x, position->y - 19 * scale->y, position->z - 1 * scale->z);
		glVertex3f(position->x + 4 * scale->x, position->y - 21 * scale->y, position->z - 1 * scale->z);
	glEnd();
}
