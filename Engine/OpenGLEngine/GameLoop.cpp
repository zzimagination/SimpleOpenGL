#include<glad/glad.h>
#include "GameLoop.h"
#include "Math/Mathz.h"
#include "Render/BaseRenderPipeline.h"
#include "Camera/Camera.h"
#include "World/WorldManager.h"
#include "Render/ShaderManager.h"
#include "Component/Components.h"
#include "2D/Texture.h"
#include "GameLogic/GameInit.h"

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
