#include "GameWindow.h"
#include <iostream>
#include <string>
#include "GameSetting.h"

namespace SemperEngine {

	namespace Core
	{
		GLWindow* GameWindow::window = nullptr;

		void GameWindow::CreateGameWindow()
		{
			int width = GameSetting::windowWidth;
			int height = GameSetting::windowHeight;

			window = GLWindow::Create(width, height, L"Ê¼ÖÕÒýÇæ");
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
	}
}