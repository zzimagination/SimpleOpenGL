#include "LogoPipeline.h"
#include "LogoCollection.h"
#include "Resource.h"
#include "RenderCollection.h"
#include "RenderBatchManager.h"
#include "GraphicCommandManager.h"
#include "ResourceObjectCenter.h"
#include "GraphicRenderer.h"
#include "Debug.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;
		using namespace chrono;

		float LogoPipeline::logoTime = 3000;

		int LogoPipeline::_current = -1;

		shared_ptr<RenderScreenObject> LogoPipeline::_renderObject = shared_ptr<RenderScreenObject>(new RenderScreenObject);

		int LogoPipeline::_next = 0;

		float LogoPipeline::_alpha = 0;

		milliseconds LogoPipeline::_time;

		time_point<system_clock> LogoPipeline::_startTime;

		bool LogoPipeline::isCompleted = false;

		vector<shared_ptr<Texture>> LogoPipeline::_logoTextures;

		void LogoPipeline::Start()
		{
			for (size_t i = 0; i < LogoCollection::files.size(); i++)
			{
				auto tex = Resource::LoadTexture(LogoCollection::files[i]);
				_logoTextures.push_back(tex);
			}
			_renderObject->material = shared_ptr<Material>(new Material("ScreenTexture"));
			_renderObject->material->renderOperation.blend = true;
			RenderCollection::AddScreenObject(_renderObject.get());
			_startTime = system_clock::now();
		}

		void LogoPipeline::Update()
		{
			if (_next != _current)
			{
				_current = _next;
				_renderObject->material->AddProperty(0, _logoTextures[_current]);
				_alpha = 0;
			}
			else
			{
				_alpha = Alpha((float)_time.count());
			}

			_renderObject->material->AddProperty("_color", Color::ColorFloat(1, 1, 1, _alpha));
			Resource();
			Render();

			auto now = system_clock::now();
			_time = duration_cast<milliseconds>(system_clock::now() - _startTime);
			if (_time.count() > (_current + 1) * logoTime)
			{
				_next = _current + 1;
			}
			if (_next >= LogoCollection::files.size())
			{
				isCompleted = true;
				return;
			}
		}

		void LogoPipeline::End()
		{
			_logoTextures.clear();
			_renderObject.reset();
			RenderCollection::ClearRenders();
			Resource();
			Render();
		}

		void LogoPipeline::Resource()
		{
			Resource::DisposeUnuse();
			ResourceObjectCenter::EndProcess();
		}

		void LogoPipeline::Render()
		{
			GraphicRenderer::Clear(Color(Float4(0, 0, 0, 1)));
			auto renderObjects = RenderCollection::GetScreenObjects();
			RenderBatchManager::GenerateBatchs(renderObjects);
			RenderBatchManager::GenerateGraphicCommands();
			RenderBatchManager::Clear();

			GraphicCommandManager::Resource();
			GraphicCommandManager::SwapCommands();
			GraphicCommandManager::Render();
		}

		float LogoPipeline::Alpha(float time)
		{
			auto t = time - logoTime * _current;

			if (t <= (0.5f * logoTime))
			{
				auto a = t / 1000.f;
				return a < 1 ? a : 1;
			}
			else if (t > (0.5f * logoTime) && t <= (2.f / 3.f * logoTime))
			{
				return 1;
			}
			else if (t > (2.f / 3.f * logoTime) && t <= logoTime)
			{
				auto t1 = t - 2.f / 3.f * logoTime;
				auto t2 = 1 - t1 / (1.f / 3.f * logoTime);
				return t2 > 0 ? t2 : 0;
			}
			return 0.0f;
		}
	}
}