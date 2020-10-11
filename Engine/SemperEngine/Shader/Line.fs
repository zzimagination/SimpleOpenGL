#version 460 core
layout (location = 0) out vec4 FragColor;

uniform vec3 _color;

void main()
{             
	FragColor=vec4(_color.xyz, 1.0);
}