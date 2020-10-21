#include "LogoPipeline.h"
#include "GraphicCommandManager.h"
#include "GraphicDataCenter.h"
#include "RenderBatch.h"
#include "GraphicResouceAPI.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		void LogoPipeline::Resource()
		{
			//auto data = TextureData::LoadFile("Resources/Textures/logo2.png");
			//auto tex = unique_ptr<TextureData>(data);
			//logoTex = GraphicResouceAPI::AddTextureData(tex.get());
		}

		void LogoPipeline::Render()
		{
			auto logoTex = Resource::LoadTexture("Resources/Textures/logo2.png");
			auto logoMat = shared_ptr<Material>(new Material("ScreenTexture"));
			logoMat->AddProperty(0, logoTex);
			logoMat->AddProperty("_color", Color(1, 1, 1, 0.3f));
			RenderBatch batch;
			batch.screenDraw = true;
			batch.material = logoMat;
			GraphicCommandManager::Resource();
			GraphicCommandManager::Clear(Color(0.9f, 0.9f, 0.9f, 1), 1);
			GraphicCommandManager::DrawScreen(batch);
			GraphicCommandManager::SwapCommands();
			GraphicCommandManager::Render();
			/*auto material = std::shared_ptr<Material>(new Material("ScreenTexture"));
			material->AddProperty("_color", Color(1, 1, 1,0.5f));
			RenderBatch batch = RenderBatch();
			batch.material = material;
			batch.screenDraw = true;
			GraphicCommandManager::BindScreenTexture();
			GraphicCommandManager::Clear(Color(0.8f, 0.8f, 0.8f, 1), 3);
			GraphicCommandManager::Draw(batch);
			GraphicCommandManager::SwapCommands();

			GraphicRender::Render();*/
		}
	}
}