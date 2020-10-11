#pragma once

#include <Windows.h>

class MyWindow
{
public:

	static void Init();

	static MyWindow* Create(
		LPCWSTR className,
		PCWSTR windowName,
		DWORD dwStyle,
		DWORD dwExStyle=0,
		int x=0,
		int y=0,
		int width=800,
		int height=600,
		HWND parent=0,
		HMENU hMenu=0
	);

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:

	static void CreateFakeContext();

	static void InitGL();

public:

	LPCWSTR className;

	PCWSTR windowName;

	DWORD dwStyle;

	DWORD dwExStyle;

	int x;

	int y;

	int width;

	int height;

	HWND parent;

	HMENU hMenu;

	HWND hwnd;

	HDC hdc;

	HGLRC hrc;

public:

	MyWindow();

	~MyWindow();

	void Destory();

	void SwapWindowBuffers();

	void PollWindowEvent();

	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

};

