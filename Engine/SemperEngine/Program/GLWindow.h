#ifndef __GWINDOW__
#define __GWINDOW__

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

namespace Semper {

	namespace Core
	{
		class GLWindow
		{
		public:

			static GLWindow* Create(int width, int height, std::wstring title);

			static GLWindow* Create(int width, int height, std::string title);

		public:

			int vsync;

		private:

			GLFWwindow* window;

		public:

			void SwapFrameBuffers();

			void Terminate();

			bool ShouldClose();

			void PollEvent();

		private:

			static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

			static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

			static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

			static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

			static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

		};
	}
}
#endif // !GWINDOW
