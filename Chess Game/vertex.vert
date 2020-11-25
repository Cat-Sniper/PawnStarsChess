#version 330 core
layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vNormal;

out vec3 normal;
out vec3 fragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 nMat;

void main(){
	vec4 hNormal = nMat * vec4(vNormal, 1.0);
	
	normal = hNormal.xyz;
	fragPos = vec3(model * vec4(vPos, 1.0));
	gl_Position = projection * view * vec4(fragPos, 1.0);
}