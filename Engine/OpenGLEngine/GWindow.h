#ifndef GWINDOW
#define GWINDOW
#include <string>
#include "EngineDef.h"

#ifdef GLFW
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#endif

#ifdef WIN32_WIN
#include "Win32Window.h"
#include <glad/glad.h>
#endif // GLFW

namespace SemperEngine {

	using namespace std;

#ifdef WIN32_WIN
	typedef Win32Window* WindowClass;
#endif
#ifdef GLFW
	typedef GLFWwindow* WindowClass;
#endif // GLFW



	class GWindow
	{
	private:

		WindowClass window;

	public:

		static GWindow* Create(int width, int height, wstring title);

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

		static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

		static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

		static void OnScroll(GLFWwindow* window, double xoffset, double yoffset);

		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
#endif // GLFW

	};
}
#endif // !GWINDOW
