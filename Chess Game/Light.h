#pragma once

#include "GlobalTypes.h"

class Light {

private:

	glm::vec3 lightPos;
	glm::mat4 lightModel;
	Shader lightShader; 

public:
	Light() : 
		lightPos(3.5f, 3.5f, 4.0f), 
		lightModel(glm::translate(identity, lightPos)),
		lightShader("lightVertex.vert", "lightFragment.frag")
		

	{}

	void applyLight(glm::mat4 view, glm::mat4 projection) {
		lightShader.bind();
		lightShader.setMat4Uniform("projection", glm::value_ptr(projection));
		lightShader.setMat4Uniform("view", glm::value_ptr(view));
		lightShader.setMat4Uniform("model", glm::value_ptr(lightModel));

	}
	glm::vec3 getPos() { return lightPos; }
};