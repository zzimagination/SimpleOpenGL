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

void GameLoop::StartBeforeLoop()
{
	ShaderManager::CompileShader();

	GameInit::Init();
}

void GameLoop::MainLoop()
{

	WorldManager::active->Live();

	BaseRenderPipeline::Render();

}
