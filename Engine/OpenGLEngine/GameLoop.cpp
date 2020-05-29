#include <iostream>

#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "GameWindow.h"
#include "FrameRuntime.h"
#include "BaseRenderPipeline.h"
#include "GameLoop.h"
#include "Time.h"
#include "Camera.h"

void GameLoop::MainLoop()
{
	GLFWwindow* window = GameWindow::gameWindow;
	while (!glfwWindowShouldClose(window))
	{
		FrameRuntime::BeginFrame();
		if (Camera::mainCamera == nullptr)
		{
			Camera* main = new Camera();
			main->Position = glm::vec3(0.0f, 0.0f, 2.5f);
			main->projection = Camera::Projection::Orthographic;
			Camera::mainCamera = main;
		}
		Camera::mainCamera->CalculateVectors();
		BaseRenderPipeline::Render();

		glfwSwapBuffers(window);
		glfwPollEvents();

		FrameRuntime::EndFrame();
	}
}
