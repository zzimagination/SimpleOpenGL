#include "GameWindow.h"
#include "GWindow.h"
#include <iostream>
#include "ProjectSetting.h"
#include <string>

namespace SemperEngine {

	GWindow* GameWindow::window = nullptr;

	void GameWindow::CreateGameWindow()
	{
		int width = ProjectSetting::GetWindowWidth();
		int height = ProjectSetting::GetWindowHeight();

		window = GWindow::Create(width, height, L"SemperEngine");
	}

	void GameWindow::TerminateGameWindow()
	{
		window->Terminate();
		delete window;
	}

	bool GameWindow::WindowShouldClose()
	{
		return window->ShouldClose();
	}

	void GameWindow::SwapFrameBuffers()
	{
		return window->SwapFrameBuffers();
	}

	void GameWindow::PollWindowEvent()
	{
		window->PollEvent();
	}

	void GameWindow::OnSizeChanged(int width, int height)
	{
		ProjectSetting::windowWidth = width;
		ProjectSetting::windowHeight = height;
	}

	void GameWindow::OnMouse(double xpos, double ypos)
	{

	}

	void GameWindow::OnScroll(double xoffset, double yoffset)
	{
	}
}