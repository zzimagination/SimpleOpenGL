#version 330 core
layout (location = 0) out vec4 FragColor;

uniform vec4 _color;

void main()
{             
	FragColor=vec4(_color.rgb,1.0);
}