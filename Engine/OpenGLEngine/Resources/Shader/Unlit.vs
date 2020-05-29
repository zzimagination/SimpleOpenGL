#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;


out vec2 TexCoords;

uniform mat4 _projection;
uniform mat4 _view;
uniform mat4 _model;

void main()
{
	TexCoords = aTexCoords;
    gl_Position =_projection* _view *_model* vec4(aPos, 1);
}