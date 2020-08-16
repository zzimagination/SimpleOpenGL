#include "GameStart.h"
#include "ShaderManager.h"
namespace SemperEngine {
	void GameStart::Start()
	{
		ShaderManager::CompileShader();
	}
}
