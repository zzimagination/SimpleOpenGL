#include "GWindow.h"
#include "GameSetting.h"
#include "GameWindow.h"
#include "KeyIdentity.h"
#include "EventRecorder.h"

namespace SemperEngine {

	namespace Core
	{
		using namespace std;

		GWindow* GWindow::Create(int width, int height, wstring title)
		{
			GWindow* gwindow = new GWindow();

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

			glfwSetCursorPosCallback(gwindow->window, GWindow::cursor_position_callback);
			glfwSetMouseButtonCallback(gwindow->window, GWindow::mouse_button_callback);
			glfwSetFramebufferSizeCallback(gwindow->window, GWindow::OnSizeChanged);
			glfwSetScrollCallback(gwindow->window, GWindow::OnScroll);
			glfwSetKeyCallback(gwindow->window, GWindow::key_callback);

			if (!gladLoadGL())
			{
				throw("Failed to initialize GLAD");
			}

			glViewport(0, 0, width, height);
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			gwindow->SwapFrameBuffers();
			return gwindow;
		}

		void GWindow::SwapFrameBuffers()
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

		void GWindow::Terminate()
		{
			glfwTerminate();
		}

		bool GWindow::ShouldClose()
		{
			return glfwWindowShouldClose(window);
		}

		void GWindow::PollEvent()
		{
			glfwPollEvents();
		}

		void GWindow::OnSizeChanged(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
			GameWindow::OnSizeChanged(width, height);
		}

		void GWindow::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		{
			EventRecorder::RecordCursorPosition((int)xpos, (int)ypos);
		}

		void GWindow::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			EventRecorder::RecordMouseButton(button, action);
		}

		void GWindow::OnScroll(GLFWwindow* window, double xoffset, double yoffset)
		{
			GameWindow::OnScroll(xoffset, yoffset);
		}
		void GWindow::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			EventRecorder::RecordKeyEvent(key, action);
		}
	}
}