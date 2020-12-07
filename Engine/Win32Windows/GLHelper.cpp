#include "GLHelper.h"
#include <glad/glad.h>

vector<float> GLHelper::points = {
		0, 0.5f, 0,
		0.4f, -0.2f, 0,
		0.4f, -0.2f, 0,
		-0.4f, -0.2f, 0,
		-0.4f, -0.2f, 0,
		0, 0.5f, 0
};

string GLHelper::vertexShader =
"layout (location = 0) in vec3 aPos;"
"void main()"
"{"
"	TexCoords = aTexCoords;"
"    gl_Position = vec4(aPos, 1);"
"}";

string GLHelper::fragmentShader =
"layout (location = 0) out vec4 FragColor;"

"void main()"
"{"
"	FragColor=vec4(1.0,0,1.0,1.0);"
"}";

unsigned int GLHelper::CompileShader(string vert, string frag)
{
	auto vertex = glCreateShader(GL_VERTEX_SHADER);
	auto vertexCStr = vert.c_str();
	glShaderSource(vertex, 1, &vertexCStr, NULL);
	glCompileShader(vertex);

	auto fragment = glCreateShader(GL_FRAGMENT_SHADER);
	auto fragCStr = vert.c_str();
	glShaderSource(fragment, 1, &fragCStr, NULL);
	glCompileShader(fragment);

	auto program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);

	glLinkProgram(program);

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	return program;
}

unsigned int GLHelper::GetVertex(vector<float> points)
{
	unsigned int VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	auto size = points.size() * 4;
	glBufferData(GL_ARRAY_BUFFER, size, points.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12, (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	return VAO;
}

void GLHelper::DrawLine()
{
}
