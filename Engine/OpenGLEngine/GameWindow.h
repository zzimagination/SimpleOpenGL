#pragma once

#include<glad/glad.h>
#include <GLFW/glfw3.h>

class GameWindow
{
public:
	static GLFWwindow* gameWindow;

	static void CreateGameWindow(int width, int height);

	static void TerminateGameWindow();

	static bool WindowShouldClose();

	static void SwapFrameBuffers();

	static void PollWindowEvent();

private:
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);

	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
};

