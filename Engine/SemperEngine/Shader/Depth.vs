#version 460 core
layout (location = 0) in vec3 aPos;

uniform mat4 _projection;
uniform mat4 _view;
uniform mat4 _model;

out vec3 viewPosition;

void main()
{
	vec4 viewPos = _view * _model * vec4(aPos, 1);
	viewPosition = viewPos.xyz;
    gl_Position = _projection * viewPos;
}