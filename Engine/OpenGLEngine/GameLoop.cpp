#include<glad/glad.h>
#include "GameLoop.h"
#include "Mathz.hpp"
#include "BaseRenderPipeline.h"
#include "Camera.h"
#include "WorldManager.h"
#include "ShaderManager.h"
#include "Components.h"
#include "Texture.h"
#include "GameInit.h"
#include "GameWindow.h"
#include "FrameRuntime.h"

bool GameLoop::isLooping = true;

void GameLoop::BeforeLoop()
{
	GameInit::Init();
	isLooping = true;
}

void GameLoop::MainLoop()
{
	while (isLooping) 
	{
		if (GameWindow::WindowShouldClose())
		{
			break;
		}
		GameWindow::PollWindowEvent();
		FrameRuntime::BeginFrame();
		WorldManager::LiveWorld();
		BaseRenderPipeline::Render();
		FrameRuntime::EndFrame();
		GameWindow::SwapFrameBuffers();
	}
}
