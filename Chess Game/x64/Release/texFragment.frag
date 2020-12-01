#version 330 core

in vec2 tCoord;

uniform sampler2D Tex1;

out vec4 fColor;

void main(){
	fColor = texture(Tex1, tCoord);
}