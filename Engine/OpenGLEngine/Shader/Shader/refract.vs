#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 2) in vec3 aNormal;

out vec3 Normal;
out vec3 Position;
layout (std140) uniform Matrices
{
    mat4 projection;
    mat4 view;
};
uniform mat4 _model;

void main()
{
    Normal = mat3(transpose(inverse(_model))) * aNormal;
    Position = vec3(_model * vec4(aPos, 1.0));
    gl_Position = projection * view * _model * vec4(aPos, 1.0);
}