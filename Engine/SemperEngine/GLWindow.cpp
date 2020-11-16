#include "GLWindow.h"
#include "GameSetting.h"
#include "GameWindow.h"
#include "EventRecorder.h"

namespace SemperEngine {

	namespace Core
	{
		using namespace std;

		GLWindow* GLWindow::Create(int width, int height, wstring title)
		{
			GLWindow* gwindow = new GLWindow();

			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			gwindow->window = glfwCreateWindowEX(width, height, title.c_str(), NULL, NULL);
			if (gwindow->window == NULL)
			{
				throw "Failed to create GLFW window";
				glfwTerminate();
			}
			glfwMakeContextCurrent(gwindow->window);

			glfwSetCursorPosCallback(gwindow->window, GLWindow::cursor_position_callback);
			glfwSetMouseButtonCallback(gwindow->window, GLWindow::mouse_button_callback);
			glfwSetFramebufferSizeCallback(gwindow->window, GLWindow::framebuffer_size_callback);
			glfwSetScrollCallback(gwindow->window, GLWindow::scroll_callback);
			glfwSetKeyCallback(gwindow->window, GLWindow::key_callback);

			if (!gladLoadGL())
			{
				throw("Failed to initialize GLAD");
			}

			glViewport(0, 0, width, height);
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
			gwindow->SwapFrameBuffers();
			return gwindow;
		}

		void GLWindow::SwapFrameBuffers()
		{
			auto v = GameSetting::vsync;
			if (1 == v)
			{
				glfwSwapInterval(1);
			}
			else if (2 == v)
			{
				glfwSwapInterval(2);
			}
			glfwSwapBuffers(window);
		}

		void GLWindow::Terminate()
		{
			glfwTerminate();
		}

		bool GLWindow::ShouldClose()
		{
			return glfwWindowShouldClose(window);
		}

		void GLWindow::PollEvent()
		{
			glfwPollEvents();
		}

		void GLWindow::framebuffer_size_callback(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
			GameWindow::OnSizeChanged(width, height);
		}

		void GLWindow::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		{
			EventRecorder::RecordCursorPosition((int)xpos, (int)ypos);
		}

		void GLWindow::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			EventRecorder::RecordMouseButton(button, action);
		}

		void GLWindow::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
		{
		}

		void GLWindow::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			EventRecorder::RecordKeyEvent(key, action);
		}
	}
}