#include "GWindow.h"
#include "ProjectSetting.h"
#include "GameWindow.h"
#include "KeyIdentity.h"
#include "EventRecorder.h"
#include <string>

namespace SemperEngine {

	GWindow* GWindow::Create(int width, int height, wstring title)
	{
		GWindow* gwindow = new GWindow();

#ifdef WIN32_WIN
		gwindow->window = new Win32Window();

		//int len;
		//int slength = (int)title.length() + 1;
		//len = MultiByteToWideChar( CP_ACP, 0, title.c_str(), slength, 0, 0);
		//wchar_t* buf = new wchar_t[len];
		//MultiByteToWideChar(CP_ACP, 0, title.c_str(), slength, buf, len);
		//std::wstring r(buf);
		//delete[] buf;

		gwindow->window->Create(title.c_str(), WS_OVERLAPPEDWINDOW, 0, 0, 0, width, height);
		gwindow->window->OnSizeChanged = &GWindow::OnSizeChanged;
		gladLoadGL();
#endif // WIN32_WIN

#ifdef GLFW
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		
		gwindow->window = glfwCreateWindowEX(width, height, L"SemperEngine", NULL, NULL);
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

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			throw("Failed to initialize GLAD");
		}

#endif // GLFW

		glViewport(0, 0, width, height);
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		gwindow->SwapFrameBuffers();
		return gwindow;
	}

	void GWindow::SwapFrameBuffers()
	{
#ifdef WIN32_WIN
		window->SwapWindowBuffers();
#endif // WIN32_WIN

#ifdef GLFW
		glfwSwapBuffers(window);
#endif // GLFW

	}

	void GWindow::Terminate()
	{
#ifdef WIN32_WIN
		window->Destory();
		delete window;
#endif // WIN32_WIN

#ifdef GLFW
		glfwTerminate();
#endif // GLFW

	}

	bool GWindow::ShouldClose()
	{
#ifdef WIN32_WIN
		return window->shouldClose;
#endif // WIN32_WIN

#ifdef GLFW
		return glfwWindowShouldClose(window);
#endif // GLFW

		return false;
	}

	void GWindow::PollEvent()
	{
#ifdef WIN32_WIN
		window->PollWindowEvent();
#endif // !WIN32_WIN

#ifdef GLFW
		glfwPollEvents();
#endif // GLFW
	}

#ifdef WIN32_WIN

	void GWindow::OnSizeChanged(int width, int height)
	{
		glViewport(0, 0, width, height);
		GameWindow::OnSizeChanged(width, height);
	}

	void GWindow::OnMouse(double xpos, double ypos)
	{
		GameWindow::OnMouse(xpos, ypos);
	}

	void GWindow::OnScroll(double xoffset, double yoffset)
	{
		GameWindow::OnScroll(xoffset, yoffset);
	}


#endif // WIN32_WIN


#ifdef GLFW

	void GWindow::OnSizeChanged(GLFWwindow * window, int width, int height)
	{
		glViewport(0, 0, width, height);
		GameWindow::OnSizeChanged(width, height);
	}

	void GWindow::cursor_position_callback(GLFWwindow * window, double xpos, double ypos)
	{
		EventRecorder::RecordCursorPosition(xpos, ypos);
	}

	void GWindow::mouse_button_callback(GLFWwindow * window, int button, int action, int mods)
	{
		EventRecorder::RecordMouseButton(button, action);
	}

	void GWindow::OnScroll(GLFWwindow * window, double xoffset, double yoffset)
	{
		GameWindow::OnScroll(xoffset, yoffset);
	}
	void GWindow::key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
	{
		EventRecorder::RecordKeyEvent(key, action);
	}
#endif // GLFW
}
