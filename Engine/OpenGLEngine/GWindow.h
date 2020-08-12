#ifndef GWINDOW
#define GWINDOW

#include <string>

using namespace std;

//#define WIN32_WIN

#ifndef WIN32_WIN
#define GLFW
#endif // !WIN32


#ifdef WIN32_WIN
#include "Win32Window.h"
typedef Win32Window* WindowClass;

#endif // WIN32_WIN

#ifdef GLFW
#include <glad/glad.h>
#include <GLFW/glfw3.h>
typedef GLFWwindow* WindowClass;

#endif // GLFW



class GWindow
{
private:

	WindowClass window;

public:

	static GWindow* Create(int width, int height, string title);

public:

	void SwapFrameBuffers();

	void Terminate();

	bool ShouldClose();

	void PollEvent();

private:

#ifdef WIN32_WIN
	static void OnSizeChanged(int width, int height);

	static void OnMouse(double xpos, double ypos);

	static void OnScroll(double xoffset, double yoffset);
#endif // WIN32_WIN

#ifdef GLFW
	static void OnSizeChanged(GLFWwindow* window, int width, int height);

	static void OnMouse(GLFWwindow* window, double xpos, double ypos);

	static void OnScroll(GLFWwindow* window, double xoffset, double yoffset);
#endif // GLFW

};

#endif // !GWINDOW
