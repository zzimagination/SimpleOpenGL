#include "Win32Window.h"
#ifdef WIN32_WIN


#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glext.h>
#include <gl/wglext.h>

namespace SemperEngine {

	PFNWGLSWAPINTERVALEXTPROC       wglSwapIntervalEXT = NULL;
	PFNWGLGETSWAPINTERVALEXTPROC    wglGetSwapIntervalEXT = NULL;

	void(*Win32Window::OnSizeChanged)(int, int);

	LRESULT Win32Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		Win32Window *pThis = nullptr;
		if (uMsg == WM_NCCREATE)
		{
			CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
			pThis = (Win32Window*)pCreate->lpCreateParams;
			if (pThis == nullptr)
			{
				return DefWindowProc(hwnd, uMsg, wParam, lParam);
			}
			SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pThis);
			pThis->m_hwnd = hwnd;
		}
		else
		{
			pThis = (Win32Window*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
		}
		if (pThis)
		{
			return pThis->HandleMessage(uMsg, wParam, lParam);
		}
		else
		{
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
	}

	Win32Window::Win32Window()
	{
		m_hwnd = nullptr;
	}

	Win32Window::~Win32Window()
	{
	}

	BOOL Win32Window::Create(PCWSTR lpWindowName, DWORD dwStyle, DWORD dwExStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu)
	{
		HINSTANCE instance = GetModuleHandle(NULL);

		WNDCLASSEX wcex = { 0 };
		memset(&wcex, 0, sizeof(wcex));
		wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wcex.cbSize = sizeof(wcex);
		wcex.lpfnWndProc = Win32Window::WindowProc;
		wcex.hInstance = instance;
		wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
		wcex.lpszClassName = ClassName();
		if (!RegisterClassEx(&wcex))
		{
			abort();
		}

		HWND fakeHwnd = CreateWindowEx(
			dwExStyle, ClassName(), lpWindowName, dwStyle, x, y,
			nWidth, nHeight, hWndParent, hMenu, instance, nullptr
		);
		if (!fakeHwnd)
		{
			abort();
		}

		ShowWindow(m_hwnd, SW_SHOW);

		PIXELFORMATDESCRIPTOR fakePFD;
		memset(&fakePFD, 0, sizeof(fakePFD));
		fakePFD.nSize = sizeof(fakePFD);
		fakePFD.nVersion = 1;
		fakePFD.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		fakePFD.iPixelType = PFD_TYPE_RGBA;
		fakePFD.cColorBits = 32;
		fakePFD.cDepthBits = 24;
		fakePFD.cStencilBits = 8;
		fakePFD.iLayerType = PFD_MAIN_PLANE;

		HDC fakeDC = GetDC(fakeHwnd);
		int fakePF = ChoosePixelFormat(fakeDC, &fakePFD);
		if (fakePF == 0)
		{
			abort();
		}

		if (!SetPixelFormat(fakeDC, fakePF, &fakePFD))
		{
			abort();
		}

		HGLRC fakeRC = wglCreateContext(fakeDC);
		if (fakeRC == 0)
		{
			abort();
		}
		wglMakeCurrent(fakeDC, fakeRC);

		PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = nullptr;
		wglChoosePixelFormatARB = reinterpret_cast<PFNWGLCHOOSEPIXELFORMATARBPROC>(wglGetProcAddress("wglChoosePixelFormatARB"));
		if (wglChoosePixelFormatARB == nullptr)
		{
			abort();
		}
		PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = nullptr;
		wglCreateContextAttribsARB = reinterpret_cast<PFNWGLCREATECONTEXTATTRIBSARBPROC>(wglGetProcAddress("wglCreateContextAttribsARB"));
		if (wglCreateContextAttribsARB == nullptr)
		{
			abort();
		}

		m_hwnd = CreateWindowEx(
			dwExStyle, ClassName(), lpWindowName, dwStyle, x, y,
			nWidth, nHeight, hWndParent, hMenu, instance, this
		);

		hDC = GetDC(m_hwnd);

		const int pixelAttribs[] = {
			WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
			WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
			WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
			WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
			WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
			WGL_COLOR_BITS_ARB, 32,
			WGL_ALPHA_BITS_ARB, 8,
			WGL_DEPTH_BITS_ARB, 24,
			WGL_STENCIL_BITS_ARB, 8,
			WGL_SAMPLE_BUFFERS_ARB, GL_TRUE,
			WGL_SAMPLES_ARB, 4,
			0
		};
		int pixelFormatID;
		UINT numFormats;
		bool status = wglChoosePixelFormatARB(hDC, pixelAttribs, NULL, 1, &pixelFormatID, &numFormats);
		if (status == false || numFormats == 0)
		{
			abort();
		}

		PIXELFORMATDESCRIPTOR PFD;
		DescribePixelFormat(hDC, pixelFormatID, sizeof(PFD), &PFD);
		SetPixelFormat(hDC, pixelFormatID, &PFD);

		const int major_min = 4, minor_min = 5;
		int  contextAttribs[] = {
		WGL_CONTEXT_MAJOR_VERSION_ARB, major_min,
		WGL_CONTEXT_MINOR_VERSION_ARB, minor_min,
		WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
		0
		};
		hRC = wglCreateContextAttribsARB(hDC, 0, contextAttribs);
		if (hRC == 0)
		{
			abort();
		}

		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(fakeRC);
		ReleaseDC(fakeHwnd, fakeDC);
		DestroyWindow(fakeHwnd);
		wglMakeCurrent(hDC, hRC);

		ShowWindow(m_hwnd, SW_SHOW);

		wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
		wglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXTPROC)wglGetProcAddress("wglGetSwapIntervalEXT");

		return (m_hwnd ? TRUE : FALSE);
	}

	void Win32Window::Destory()
	{
		wglMakeCurrent(NULL, NULL);
		ReleaseDC(m_hwnd, hDC);
		wglDeleteContext(hRC);
		DestroyWindow(m_hwnd);
	}

	void Win32Window::SwapWindowBuffers()
	{
		if (project_vsync == vsync) {
			wglSwapIntervalEXT(1);
		}
		else if(project_vsync == helf)
		{
			wglSwapIntervalEXT(2);
		}
		SwapBuffers(hDC);
	}

	void Win32Window::PollWindowEvent()
	{
		MSG msg = { };
		if (PeekMessage(&msg, m_hwnd, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				shouldClose = true;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				shouldClose = true;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	HWND Win32Window::Window() const
	{
		return  m_hwnd;
	}

	PCWSTR Win32Window::ClassName()
	{
		return  L"GameWindow";
	}

	LRESULT Win32Window::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		case WM_SIZE:
			if (OnSizeChanged != nullptr) {
				OnSizeChanged(LOWORD(lParam), HIWORD(lParam));
			}
			return 0;
		default:
			return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
		}
		return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
	}
}
#endif // WIN32_WIN