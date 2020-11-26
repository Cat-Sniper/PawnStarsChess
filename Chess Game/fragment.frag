#version 330 core

in vec3 normal;
in vec3 fragPos;

out vec4 FragColor;

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 objectColor;

void main(){
	vec3 lightColor = vec3(1.0, 1.0, 1.0);

	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(lightPos - fragPos);

	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;

	float ambientStrength = 0.25;
	vec3 ambient = ambientStrength * lightColor;

	float specularStrength = 0.5;
	vec3 viewDir = normalize(vec3(viewPos - fragPos));
	vec3 reflectDir = normalize(reflect(-lightDir, norm));

	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 256);
	vec3 specular = specularStrength * spec * lightColor;

	FragColor = vec4((ambient + diffuse + specular) * objectColor, 1.0);
}