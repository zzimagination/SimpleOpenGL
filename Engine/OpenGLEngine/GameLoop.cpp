#include <iostream>

#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include "GameWindow.h"
#include "FrameRuntime.h"
#include "BaseRenderPipeline.h"
#include "GameLoop.h"
#include "Time.h"

void GameLoop::MainLoop()
{
	GLFWwindow* window = GameWindow::gameWindow;
	while (!glfwWindowShouldClose(window))
	{
		FrameRuntime::BeginFrame();

		BaseRenderPipeline::Render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
