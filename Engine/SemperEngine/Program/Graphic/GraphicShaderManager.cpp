#include "GraphicShaderManager.h"
#include "ShaderCompiler.h"

namespace Semper 
{
	namespace Core
	{
		using namespace std;

		vector<GraphicShader*> GraphicShaderManager::_shaderList;

		vector<string> GraphicShaderManager::_shaderNameList;

		void GraphicShaderManager::Initialize()
		{
			AddShader(Shaderfile("Color", "Shader/Color.vs", "Shader/Color.fs"));
			AddShader(Shaderfile("Debug", "Shader/Debug.vs", "Shader/Debug.fs"));
			AddShader(Shaderfile("Texture", "Shader/Texture.vs", "Shader/Texture.fs"));
			AddShader(Shaderfile("ScreenTexture", "Shader/ScreenTexture.vs", "Shader/ScreenTexture.fs"));
			AddShader(Shaderfile("ScreenView", "Shader/ScreenView.vs", "Shader/ScreenView.fs"));
			AddShader(Shaderfile("Depth", "Shader/Depth.vs", "Shader/Depth.fs"));
		}

		GraphicShader* GraphicShaderManager::GetShader(std::string name)
		{
			for (size_t i = 0; i < _shaderNameList.size(); i++)
			{
				if (_shaderNameList[i] == name)
				{
					return _shaderList[i];
				}
			}
			return nullptr;
		}

		GraphicShader* GraphicShaderManager::GetShader(int id)
		{
			return _shaderList[id];
		}

		int GraphicShaderManager::GetShaderID(std::string name)
		{
			for (size_t i = 0; i < _shaderNameList.size(); i++)
			{
				if (_shaderNameList[i] == name)
				{
					return (int)i;
				}
			}
			return -1;
		}

		void GraphicShaderManager::AddShader(Shaderfile&& file)
		{
			_shaderNameList.push_back(file.name);
			auto shader = ShaderCompiler::Compile(file);
			_shaderList.push_back(shader);
		}
	}
}