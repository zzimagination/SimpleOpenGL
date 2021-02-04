#include "LogoPipeline.h"
#include "LogoCollection.h"
#include "Resource.h"
#include "RenderCollection.h"
#include "RenderBatchManager.h"
#include "GraphicCommandManager.h"
#include "ResourceSystem.h"
#include "GraphicRenderer.h"
#include "Debug.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;
		using namespace chrono;

		shared_ptr<RenderScreenObject> LogoPipeline::_renderObject;

		float LogoPipeline::logoTime = 3000;

		int LogoPipeline::_current = -1;

		int LogoPipeline::_total;

		int LogoPipeline::_next = 0;

		float LogoPipeline::_alpha = 0;

		milliseconds LogoPipeline::_time;

		time_point<system_clock> LogoPipeline::_startTime;

		bool LogoPipeline::isCompleted = false;

		vector<shared_ptr<Texture>> LogoPipeline::_logoTextures;

		void LogoPipeline::Start()
		{
			LoadResource();
			_startTime = system_clock::now();
			_current = 0;
			_renderObject->material->AddProperty("_color", Color::ColorFloat(1, 1, 1, _alpha));
			_renderObject->material->AddProperty(0, _logoTextures[_current]);
		}

		void LogoPipeline::Update()
		{
			auto interval = chrono::duration_cast<milliseconds>(system_clock::now() - _startTime).count();
			auto base = logoTime * _current;
			if (interval > base + logoTime)
			{
				_current++;
				if (_current == _total)
				{
					isCompleted = true;
					return;
				}
				_alpha = 0;
				_renderObject->material->AddProperty("_color", Color::ColorFloat(1, 1, 1, _alpha));
				_renderObject->material->AddProperty(0, _logoTextures[_current]);
				_startTime = system_clock::now();
				return;
			}

			auto t = (interval - base) / logoTime;
			_alpha = Alpha(t);
			_renderObject->material->AddProperty("_color", Color::ColorFloat(1, 1, 1, _alpha));
			Render();
		}

		void LogoPipeline::End()
		{
			_logoTextures.clear();
			_renderObject.reset();
			ResourceSystem::DisposeUnused();
		}

		void LogoPipeline::LoadResource()
		{
			LogoCollection collection;
			_total = (int)collection.files.size();
			for (size_t i = 0; i < collection.files.size(); i++)
			{
				auto tex = Resource::LoadTexture(collection.files[i]);
				_logoTextures.push_back(tex);
			}

			_renderObject = shared_ptr<RenderScreenObject>(new RenderScreenObject);
			_renderObject->material = shared_ptr<Material>(new Material("ScreenTexture"));
			_renderObject->material->Blend(true);

			ResourceSystem::EndProcess();
		}

		void LogoPipeline::Render()
		{
			GraphicRenderer::Clear(Color(Float4(0, 0, 0, 1)));
			RenderBatchManager::GenerateBatch(_renderObject.get());
			RenderBatchManager::GenerateGraphicCommands();
			RenderBatchManager::Clear();

			GraphicCommandManager::Resource();
			GraphicCommandManager::SwapCommands();
			GraphicCommandManager::Render();
		}

		float LogoPipeline::Alpha(float time)
		{
			if (time < 0.3f)
			{
				time = time / 0.3f;
				return Math::SinR(time * Math::pi / 2);
			}
			else if (time < 0.7f)
			{
				return 1;
			}
			else if (time <= 1)
			{
				time = 1 - (time - 0.7f) / 0.3f;
				return Math::SinR(time * Math::pi / 2 - Math::pi / 2);
			}
			return 0.0f;
		}
	}
}