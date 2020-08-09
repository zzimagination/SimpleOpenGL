#ifndef WIN32_WINDOW
#define WIN32_WINDOW

#include <Windows.h>

class Win32Window {
public:

	bool shouldClose;

private:

	HWND m_hwnd;

	HDC hDC;

	HGLRC hRC;

public:

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:

	Win32Window();

	~Win32Window();

	BOOL Create(
		PCWSTR lpWindowName,
		DWORD dwStyle,
		DWORD dwExStyle = 0,
		int x = CW_USEDEFAULT,
		int y = CW_USEDEFAULT,
		int nWidth = CW_USEDEFAULT,
		int nHeight = CW_USEDEFAULT,
		HWND hWndParent = 0,
		HMENU hMenu = 0
	);

	void Destory();

	void SwapWindowBuffers();

	void PollWindowEvent();

	HWND Window() const;

	PCWSTR  ClassName();

	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

};

#endif // !WIN32_WINDOW
