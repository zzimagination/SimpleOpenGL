#ifndef __GWINDOW__
#define __GWINDOW__

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

namespace SemperEngine {

	namespace Core
	{
		typedef GLFWwindow* WindowClass;

		class GWindow
		{
		private:

			WindowClass window;

		public:

			static GWindow* Create(int width, int height, std::wstring title);

		public:

			void SwapFrameBuffers();

			void Terminate();

			bool ShouldClose();

			void PollEvent();

		private:

			static void OnSizeChanged(GLFWwindow* window, int width, int height);

			static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

			static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

			static void OnScroll(GLFWwindow* window, double xoffset, double yoffset);

			static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

		};
	}
}
#endif // !GWINDOW
