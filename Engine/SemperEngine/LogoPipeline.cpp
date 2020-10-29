#include "LogoPipeline.h"
#include "GraphicCommandManager.h"
#include "GraphicDataCenter.h"
#include "RenderBatch.h"
#include "GraphicResouceAPI.h"
#include "LogoCollection.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;
		using namespace chrono;

		vector<shared_ptr<Texture>> LogoPipeline::logoTextures;

		shared_ptr<Material> LogoPipeline::material;

		float LogoPipeline::logoTime = 3000;

		int LogoPipeline::_current = -1;

		int LogoPipeline::_next = 0;

		float LogoPipeline::_alpha = 0;

		milliseconds LogoPipeline::_time;

		time_point<system_clock> LogoPipeline::_startTime;

		bool LogoPipeline::isCompleted = false;

		void LogoPipeline::Start()
		{
			bool t = !Do();
			if (!Do())
			{
				isCompleted = true;
				return;
			}
			LoadResources();
			_startTime = system_clock::now();
		}

		void LogoPipeline::Update()
		{
			if (!Do())
			{
				isCompleted = true;
				return;
			}

			if (_next != _current)
			{
				_current = _next;
				material->AddProperty(0, logoTextures[_current]);
				_alpha = 0;
			}
			else
			{
				_alpha = Alpha(_time.count() / 1000.f);
			}
			material->AddProperty("_color", Color(1, 1, 1, _alpha));
			Render();

			auto now = system_clock::now();
			_time = duration_cast<milliseconds>(system_clock::now() - _startTime);
			if (_time.count() > (_current + 1) * logoTime)
			{
				_next = _current + 1;
			}
			if (_next >= logoTextures.size())
			{
				isCompleted = true;
				return;
			}
		}

		void LogoPipeline::End()
		{
			Dispose();
		}

		void LogoPipeline::LoadResources()
		{
			for (int i = 0; i < LogoCollection::Count(); i++)
			{
				auto texture = Resource::LoadTexture(LogoCollection::_files[i]);
				logoTextures.push_back(texture);
			}

			material = shared_ptr<Material>(new Material("ScreenTexture"));
			material->AddProperty("_color", Color(1, 1, 1));
		}

		void LogoPipeline::Dispose()
		{
			for (int i = 0; i < logoTextures.size(); i++)
			{
				logoTextures[i].reset();
			}
			material.reset();
		}

		void LogoPipeline::Render()
		{
			RenderBatch batch;
			batch.screenDraw = true;
			batch.material = material;
			GraphicCommandManager::Resource();
			GraphicCommandManager::Clear(Color(0, 0, 0), 1);
			GraphicCommandManager::DrawScreen(batch);
			GraphicCommandManager::SwapCommands();
			GraphicCommandManager::Render();
		}

		bool LogoPipeline::Do()
		{
			auto result = LogoCollection::_files.size();
			return result > 0;
		}

		float LogoPipeline::Alpha(float time)
		{
			auto t = time - (int)(time / logoTime *1000.f) * (logoTime/1000.f);
			_alpha = _alpha + 0.017f;
			_alpha = _alpha > 1 ? 1 : _alpha;
			if (t <= 1.5)
			{
				return t;
			}
			else if (t > 1.5 && t <= 2.f)
			{
				return 1;
			}
			else if (t > 2.f && t <= 2.5f)
			{
				auto t1 = t - 2.f;
				auto t2 = 1 - 2 * t1;
				return t2;
			}
			return 0.0f;
		}
	}
}