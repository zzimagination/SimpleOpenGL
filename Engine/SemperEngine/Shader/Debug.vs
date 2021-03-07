#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;


void main()
{
    //gl_Position =_projection* _view * _model * vec4(aPos, 1);
    gl_Position = vec4(aPos, 1);
}