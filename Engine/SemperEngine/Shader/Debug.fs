#version 460 core
layout (location = 0) out vec4 FragColor;

uniform vec4 _color;
uniform sampler2D _mainTex;

void main()
{             
	FragColor = _color;
}