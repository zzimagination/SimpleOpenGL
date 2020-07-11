#include "GameWindow.h"
#include "GameLoop.h"
#include "FrameRuntime.h"

GLFWwindow* GameWindow::gameWindow = nullptr;

void GameWindow::CreateGameWindow(int width, int height)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	gameWindow = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
	if (gameWindow == NULL)
	{
		throw "Failed to create GLFW window";
		glfwTerminate();
	}
	glfwMakeContextCurrent(gameWindow);
	glfwSetInputMode(gameWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

	glfwSetFramebufferSizeCallback(gameWindow, framebuffer_size_callback);
	glfwSetCursorPosCallback(gameWindow, mouse_callback);
	glfwSetScrollCallback(gameWindow, scroll_callback);


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw("Failed to initialize GLAD");
	}
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, width, height);
}

void GameWindow::TerminateGameWindow()
{
	glfwTerminate();
}

bool GameWindow::WindowShouldClose()
{
	return glfwWindowShouldClose(gameWindow);
}

void GameWindow::SwapFrameBuffers()
{
	glfwSwapBuffers(gameWindow);
}

void GameWindow::PollWindowEvent()
{
	glfwPollEvents();
}

void GameWindow::framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void GameWindow::mouse_callback(GLFWwindow * window, double xpos, double ypos)
{
}

void GameWindow::scroll_callback(GLFWwindow * window, double xoffset, double yoffset)
{
}
