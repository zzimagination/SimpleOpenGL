#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include "Math/Mathz.h"
#include "GameWindow.h"
#include "FrameRuntime.h"
#include "Render/BaseRenderPipeline.h"
#include "GameLoop.h"
#include "Time.h"
#include "Camera/Camera.h"
#include "World/WorldManager.h"
#include "Render/ShaderManager.h"
#include "Component/Components.h"
#include "2D/Texture.h"

void GameLoop::StartBeforeLoop()
{
	ShaderManager::CompileShader();

	World* world = WorldManager::CreateWorld("main");

	Camera* main = new Camera();
	main->Position = glm::vec3(0.0f, 0.0f, 5.0f);
	main->projection = Camera::Projection::Perspective;
	main->size = 2.5f;
	main->CalculateVectors();
	world->camera = main;

	Texture* tex = new Texture();
	tex->path = "Resources/Textures/test.png";
	tex->textureType = BASE_TEXTURE;
	tex->LoadTexture();

	GameObject* cube1 = new GameObject("xiao ming");
	cube1->transform.position = vec3(0, 0, 1);
	cube1->transform.eulerAngle = vec3(0, 30, 0);
	Renderer* renderer = new Renderer();

	renderer->modelMatrix = cube1->transform.GetModelMatrix();
	renderer->AddTexture(tex);
	renderer->shader = ShaderManager::GetShader("UnlitTexture");
	renderer->func_shader= [](Shader* ss) {
		ss->setVec3("_color", glm::vec3(1.0f, 1.0f, 1.0f));
	};
	cube1->AddComponent(renderer);

	world->AddGameObject(cube1);
}

void GameLoop::MainLoop()
{
	GLFWwindow* window = GameWindow::gameWindow;
	while (!glfwWindowShouldClose(window))
	{
		FrameRuntime::BeginFrame();

		WorldManager::active->Live();

		BaseRenderPipeline::Render();

		glfwSwapBuffers(window);
		glfwPollEvents();

		FrameRuntime::EndFrame();
	}
}
