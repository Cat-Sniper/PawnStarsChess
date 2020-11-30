#ifndef ORBITING_CAMERA
#define ORBITING_CAMERA

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
private:
	glm::vec3 cameraPos;
	glm::vec3 cameraTarget;
	glm::vec3 cameraRight;
	glm::vec3 cameraUp;

	float shift;

public:
	Camera(glm::vec3 cameraPos, glm::vec3 cameraTarget, glm::vec3 cameraUp, float shift);

	glm::vec3 getViewDir();
	glm::mat4 getViewMat();
	glm::vec3 getPosition();

	void up(float delT);
	void down(float delT);
	void left(float delT);
	void right(float delT);

	void in(float delT);
	void out(float delT);
};

#endif