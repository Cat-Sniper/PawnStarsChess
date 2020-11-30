#include "Camera.h"

Camera::Camera(glm::vec3 cameraPos, glm::vec3 cameraTarget, glm::vec3 cameraUp, float shift) {
	this->cameraPos = cameraPos;
	this->cameraTarget = cameraTarget;
	this->cameraUp = cameraUp;
	this->shift = shift;
	cameraRight = glm::cross(cameraTarget - cameraPos, cameraUp);
}

glm::vec3 Camera::getViewDir() { return cameraTarget - cameraPos; }
glm::mat4 Camera::getViewMat() { return glm::lookAt(cameraPos, cameraTarget, cameraUp); }

void Camera::up(float delT) {
	glm::mat4 identity = glm::mat4(1.0f);

	glm::vec4 cameraH = glm::vec4(cameraPos.x, cameraPos.y, cameraPos.z, 1.0f);
	glm::mat4 translation = glm::translate(identity, -cameraTarget);
	cameraH = translation * cameraH;
	glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), -shift * delT, cameraRight);
	cameraH = rotation * cameraH;
	translation = glm::translate(identity, cameraTarget);
	cameraH = translation * cameraH;
	cameraPos.x = cameraH.x;
	cameraPos.y = cameraH.y;
	cameraPos.z = cameraH.z;
}

void Camera::down(float delT) {
	glm::mat4 identity = glm::mat4(1.0f);

	glm::vec4 cameraH = glm::vec4(cameraPos.x, cameraPos.y, cameraPos.z, 1.0f);
	glm::mat4 translation = glm::translate(identity, -cameraTarget);
	cameraH = translation * cameraH;
	glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), shift * delT, cameraRight);
	cameraH = rotation * cameraH;
	translation = glm::translate(identity, cameraTarget);
	cameraH = translation * cameraH;
	cameraPos.x = cameraH.x;
	cameraPos.y = cameraH.y;
	cameraPos.z = cameraH.z;
}

void Camera::left(float delT) {
	glm::mat4 identity = glm::mat4(1.0f);

	//conversion to homogeneous
	glm::vec4 cameraH = glm::vec4(cameraPos.x, cameraPos.y, cameraPos.z, 1.0f);
	glm::vec4 cameraHR = glm::vec4(cameraRight.x, cameraRight.y, cameraRight.z, 1.0f);

	//translation of the camera position
	glm::mat4 translation = glm::translate(identity, -cameraTarget);
	cameraH = translation * cameraH;

	//rotation of the camera position and right vector
	glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), -shift * delT, cameraUp);
	cameraH = rotation * cameraH;
	cameraHR = rotation * cameraHR;

	//translate camera position back
	translation = glm::translate(identity, cameraTarget);
	cameraH = translation * cameraH;

	//reassignment
	cameraPos.x = cameraH.x;
	cameraPos.y = cameraH.y;
	cameraPos.z = cameraH.z;

	cameraRight.x = cameraHR.x;
	cameraRight.y = cameraHR.y;
	cameraRight.z = cameraHR.z;
}

void Camera::right(float delT) {
	glm::mat4 identity = glm::mat4(1.0f);

	//conversion to homogeneous
	glm::vec4 cameraH = glm::vec4(cameraPos.x, cameraPos.y, cameraPos.z, 1.0f);
	glm::vec4 cameraHR = glm::vec4(cameraRight.x, cameraRight.y, cameraRight.z, 1.0f);

	//translation of the camera position
	glm::mat4 translation = glm::translate(identity, -cameraTarget);
	cameraH = translation * cameraH;

	//rotation of the camera position and right vector
	glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), shift * delT, cameraUp);
	cameraH = rotation * cameraH;
	cameraHR = rotation * cameraHR;

	//translate camera position back
	translation = glm::translate(identity, cameraTarget);
	cameraH = translation * cameraH;

	//reassignment
	cameraPos.x = cameraH.x;
	cameraPos.y = cameraH.y;
	cameraPos.z = cameraH.z;

	cameraRight.x = cameraHR.x;
	cameraRight.y = cameraHR.y;
	cameraRight.z = cameraHR.z;
}

void Camera::in(float delT) {
	glm::mat4 identity = glm::mat4(1.0f);
	float zoom = 2 * delT;

	glm::vec4 cameraH = glm::vec4(cameraPos.x, cameraPos.y, cameraPos.z, 1.0f);
	glm::mat4 translation = glm::translate(identity, glm::vec3(-3.5f, -3.5f, 0.0f));
	cameraH = translation * cameraH;
	cameraH = glm::vec4(cameraH.x * (1.0f - zoom), cameraH.y * (1.0f - zoom), cameraH.z * (1.0f - zoom), 1.0f);
	translation = glm::translate(identity, glm::vec3(3.5f, 3.5f, 0.0f));
	cameraH = translation * cameraH;

	cameraPos.x = cameraH.x;
	cameraPos.y = cameraH.y;
	cameraPos.z = cameraH.z;
}

void Camera::out(float delT) {
	glm::mat4 identity = glm::mat4(1.0f);
	float zoom = 2 * delT;

	glm::vec4 cameraH = glm::vec4(cameraPos.x, cameraPos.y, cameraPos.z, 1.0f);
	glm::mat4 translation = glm::translate(identity, glm::vec3(-3.5f, -3.5f, 0.0f));
	cameraH = translation * cameraH;
	cameraH = glm::vec4(cameraH.x * (1.0f + zoom), cameraH.y * (1.0f + zoom), cameraH.z * (1.0f + zoom), 1.0f);
	translation = glm::translate(identity, glm::vec3(3.5f, 3.5f, 0.0f));
	cameraH = translation * cameraH;

	cameraPos.x = cameraH.x;
	cameraPos.y = cameraH.y;
	cameraPos.z = cameraH.z;
}