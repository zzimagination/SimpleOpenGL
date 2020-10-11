#include "Program.h"
#include <iostream>
#include <fstream>
#include "MyWindow.h"
#include <glad/glad.h>
#include "../SemperEngine/GLShaderAPI.h"
#include "../SemperEngine/GLRendererAPI.h"
#include "../SemperEngine/GLResourceAPI.h"
#include "../SemperEngine/Vector3.h"

using namespace SemperEngine::Core::GraphicAPI;
using namespace SemperEngine;

int main()
{
	MyWindow::Init();
	MyWindow* window = MyWindow::Create(L"GameWindow", L"HelloWorld", WS_OVERLAPPEDWINDOW, 0, 0, 0, 800, 600);
	gladLoadGL();
	glClearColor(0.0, 0.0, 0.0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	std::ifstream vs;
	vs.open("../SemperEngine/Shader/Line.vs", std::ios_base::in);
	std::stringstream vss;
	vss<<vs.rdbuf();

	std::ifstream fs;
	fs.open("../SemperEngine/Shader/Line.fs", std::ios_base::in);
	std::stringstream fss;
	fss << fs.rdbuf();
	auto shader = GLShaderCompiler::Compile(vss.str(), fss.str(), "");

	Vector3 points[6] = {
		Vector3(0, 0.5f, 0),
		Vector3(0.4f, -0.2f, 0),
		Vector3(0.4f, -0.2f, 0),
		Vector3(-0.4f, -0.2, 0),
		Vector3(-0.4f, -0.2, 0),
		Vector3(0, 0.5f, 0)
	};

	auto vdata = GLResourceAPI::AddVertexData(points, 6);
	GLRenderAPI::BindVertexBuffer(vdata.VAO);
	GLRenderAPI::SetShader(shader.program);
	GLRenderAPI::SetShaderValue("_color", Vector3(1, 0, 0));
	GLRenderAPI::DrawLines(18);
	window->SwapWindowBuffers();

	while (true)
	{
		window->PollWindowEvent();
	}

	window->Destory();
	delete window;
	return 0;
}
