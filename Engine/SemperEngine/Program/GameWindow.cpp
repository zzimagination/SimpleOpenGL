#include "GameWindow.h"
#include <iostream>
#include <string>
#include "GameSetting.h"

namespace Semper {

	namespace Core
	{
		using namespace std;

		GLWindow* GameWindow::window = nullptr;

		void GameWindow::CreateGameWindow()
		{
			int width = GameSetting::windowWidth;
			int height = GameSetting::windowHeight;
			wstring title = GameSetting::gameTitle;
			window = GLWindow::Create(width, height, title);

			int vsync = 0;
			switch (GameSetting::vsync)
			{
			case GameSetting::Vsync::none:
				vsync = 0;
				break;
			case GameSetting::Vsync::half:
				vsync = 2;
				break;
			case GameSetting::Vsync::vsync:
				vsync = 1;
				break;
			default:
				vsync = 0;
				break;
			}
			window->vsync = vsync;
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