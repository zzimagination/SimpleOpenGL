#include "GameWindow.h"
#include "GWindow.h"
#include <iostream>
#include "GameSetting.h"
#include <string>

namespace SemperEngine {

	namespace Core
	{
		GWindow* GameWindow::window = nullptr;

		void GameWindow::CreateGameWindow()
		{
			int width = GameSetting::windowWidth;
			int height = GameSetting::windowHeight;

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
			GameSetting::windowWidth = width;
			GameSetting::windowHeight = height;
		}

		void GameWindow::OnMouse(double xpos, double ypos)
		{

		}

		void GameWindow::OnScroll(double xoffset, double yoffset)
		{
		}
	}
}