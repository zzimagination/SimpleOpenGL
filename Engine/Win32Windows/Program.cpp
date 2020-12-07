#include "Program.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include "MyWindow.h"
#include <glad/glad.h>
#include "../SemperEngine/GLShaderAPI.h"
#include "../SemperEngine/GLRendererAPI.h"
#include "../SemperEngine/GLResourceAPI.h"
#include "../SemperEngine/Float3.h"
#include "GLHelper.h"

using namespace SemperEngine::Core::GraphicAPI;
using namespace SemperEngine;

int main()
{
	MyWindow::Init();
	MyWindow* window = MyWindow::Create(L"GameWindow", L"HelloWorld", WS_OVERLAPPEDWINDOW, 0, 0, 0, 800, 600);
	gladLoadGL();
	glClearColor(0.0, 0.0, 0.0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	auto shader = GLHelper::CompileShader(GLHelper::vertexShader, GLHelper::fragmentShader);
	auto vertex = GLHelper::GetVertex(GLHelper::points);
	glBindVertexArray(vertex);
	glUseProgram(shader);
	glDrawArrays(GL_LINES, 0, GLHelper::points.size() / 3);

	window->SwapWindowBuffers();

	while (true)
	{
		window->PollWindowEvent();
	}

	window->Destory();
	delete window;
	return 0;
}
