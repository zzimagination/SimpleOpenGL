#version 460 core
layout (location = 0) in vec3 aPos;

in vec3 viewPosition;

void main()
{
    gl_Position = vec4(aPos, 1);
}