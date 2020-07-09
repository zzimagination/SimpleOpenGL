#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 _dirLightSpaceMatrix;
uniform mat4 _model;

void main()
{
    gl_Position = _dirLightSpaceMatrix * _model * vec4(aPos, 1.0);
}