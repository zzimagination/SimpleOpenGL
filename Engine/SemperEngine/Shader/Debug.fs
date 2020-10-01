#version 460 core
layout (location = 0) out vec4 FragColor;

in vec3 localPos;

uniform vec3 Color;

void main()
{             
	FragColor=vec4(0.9, 0.9, 0.9, 1.0);
}