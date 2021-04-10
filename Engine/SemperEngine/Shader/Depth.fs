#version 460 core
layout (location = 0) out vec4 FragColor;

uniform float _NFDis;

in vec3 viewPosition;

void main()
{   
	float z =  viewPosition.z * -1;
	z = clamp(z, 0, _NFDis);
	z = 1 - z / _NFDis;
    vec4 color = vec4(z, z, z, 1);
	FragColor = color;
}