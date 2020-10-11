#include "MyWindow.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glext.h>
#include <gl/wglext.h>


PFNWGLSWAPINTERVALEXTPROC       wglSwapIntervalEXT = nullptr;
PFNWGLGETSWAPINTERVALEXTPROC    wglGetSwapIntervalEXT = nullptr;
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = nullptr;
PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = nullptr;

void MyWindow::Init()
{
	CreateFakeContext();
}

MyWindow* MyWindow::Create(
	LPCWSTR className, PCWSTR windowName, DWORD dwStyle, DWORD dwExStyle,
	int x, int y, int width, int height, HWND parent, HMENU hMenu
)
{
	HINSTANCE instance = GetModuleHandle(NULL);

	WNDCLASSEX wcex = { 0 };
	memset(&wcex, 0, sizeof(wcex));
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wcex.cbSize = sizeof(wcex);
	wcex.lpfnWndProc = MyWindow::WindowProc;
	wcex.hInstance = instance;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.lpszClassName = className;
	if (!RegisterClassEx(&wcex))
	{
		abort();
	}

	auto window = new MyWindow();
	auto m_hwnd = CreateWindowEx(
		dwExStyle, className, windowName, dwStyle, x, y,
		width, height, parent, hMenu, instance, window
	);


	HDC hDC = GetDC(m_hwnd);
	HGLRC hRC = 0;
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
		abort();
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
		abort();

	wglMakeCurrent(hDC, hRC);
	ShowWindow(m_hwnd, SW_SHOW);

	window->className = className;
	window->windowName = windowName;
	window->dwStyle = dwStyle;
	window->dwExStyle = dwExStyle;
	window->x = x;
	window->y = y;
	window->width = width;
	window->height = height;
	window->parent = parent;
	window->hMenu = hMenu;
	window->hwnd = m_hwnd;
	window->hdc = hDC;
	window->hrc = hRC;
	return window;
}


void MyWindow::CreateFakeContext()
{
	HINSTANCE instance = GetModuleHandle(NULL);

	WNDCLASSEX wcex = { 0 };
	memset(&wcex, 0, sizeof(wcex));
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wcex.cbSize = sizeof(wcex);
	wcex.lpfnWndProc = MyWindow::WindowProc;
	wcex.hInstance = instance;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.lpszClassName = L"InitFakeWindow";
	if (!RegisterClassEx(&wcex))
	{
		abort();
	}

	HWND fakeHwnd = CreateWindowEx(
		0, L"InitFakeWindow", L"First", WS_DISABLED, 0, 0,
		800, 600, 0, 0, instance, nullptr
	);
	if (!fakeHwnd)
	{
		abort();
	}

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

	InitGL();
	if (wglChoosePixelFormatARB == nullptr || wglCreateContextAttribsARB == nullptr)
	{
		abort();
	}

	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(fakeRC);
	ReleaseDC(fakeHwnd, fakeDC);
	DestroyWindow(fakeHwnd);
}

void MyWindow::InitGL()
{
	wglChoosePixelFormatARB = reinterpret_cast<PFNWGLCHOOSEPIXELFORMATARBPROC>(wglGetProcAddress("wglChoosePixelFormatARB"));
	wglCreateContextAttribsARB = reinterpret_cast<PFNWGLCREATECONTEXTATTRIBSARBPROC>(wglGetProcAddress("wglCreateContextAttribsARB"));
	wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
	wglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXTPROC)wglGetProcAddress("wglGetSwapIntervalEXT");
}

LRESULT MyWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	MyWindow* pThis = nullptr;
	if (uMsg == WM_NCCREATE)
	{
		CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
		pThis = (MyWindow*)pCreate->lpCreateParams;
		if (pThis == nullptr)
		{
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
		SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pThis);
		pThis->hwnd = hwnd;
	}
	else
	{
		pThis = (MyWindow*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
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

MyWindow::MyWindow()
{
	className = L"";
	windowName = L"";
	dwStyle = 0;
	dwExStyle = 0;
	x = 0;
	y = 0;
	width = 800;
	height = 600;
	parent = 0;
	hMenu = 0;
	hwnd = 0;
	hdc = 0;
	hrc = 0;
}

MyWindow::~MyWindow()
{
}


void MyWindow::Destory()
{
	auto h = wglGetCurrentContext();
	if (h == hrc)
	{
		wglMakeCurrent(NULL, NULL);
	}
	ReleaseDC(hwnd, hdc);
	wglDeleteContext(hrc);
	DestroyWindow(hwnd);
}

void MyWindow::SwapWindowBuffers()
{
	wglSwapIntervalEXT(1);//1是全垂直同步，2为半垂直同步。
	SwapBuffers(hdc);
}

void MyWindow::PollWindowEvent()
{
	MSG msg = { };
	if (PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
		{
			Destory();
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	else if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
		{
			Destory();
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

LRESULT MyWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_SIZE:
		//if (OnSizeChanged != nullptr) {
		//	OnSizeChanged(LOWORD(lParam), HIWORD(lParam));
		//}
		glViewport(0, 0, LOWORD(lParam), HIWORD(lParam));
		return 0;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}