#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;

out vec2 TexCoords;

layout (std140) uniform Matrices
{
    mat4 projection;
    mat4 view;
};

uniform mat4 _model;

void main()
{
    gl_Position = projection * view * _model * vec4(aPos, 1.0);
    TexCoords = aTexCoords;
}