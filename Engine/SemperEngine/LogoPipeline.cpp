#include "LogoPipeline.h"
#include "LogoCollection.h"
#include "GraphicCommandManager.h"
#include "ResourceLoader.h"
#include "GraphicResouceAPI.h"
#include "GraphicRenderAPI.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;
		using namespace chrono;

		float LogoPipeline::logoTime = 3000;

		int LogoPipeline::_current = -1;

		GraphicVertexData LogoPipeline::_graphicVertex;

		GraphicTextureData LogoPipeline::_graphicTexture;

		int LogoPipeline::_next = 0;

		float LogoPipeline::_alpha = 0;

		milliseconds LogoPipeline::_time;

		time_point<system_clock> LogoPipeline::_startTime;

		bool LogoPipeline::isCompleted = false;

		void LogoPipeline::Start()
		{
			if (Completed())
			{
				return;
			}
			_graphicVertex = GenerateScreenVertex();
			GraphicRenderAPI::SetVertexData(_graphicVertex);
			GraphicRenderAPI::SetShader("ScreenTexture");
			_current = _next;
			auto texData = ResourceLoader::LoadTexture(FullPath(LogoCollection::files[_current]));
			_graphicTexture = GraphicResouceAPI::AddTextureData(texData);
			delete texData;
			GraphicRenderAPI::SetClearColor(Color(0, 0, 0, 1));
			GraphicRenderAPI::SetBlend(true);
			GraphicRenderAPI::SetBlendFunc();
			_startTime = system_clock::now();
		}

		void LogoPipeline::Update()
		{
			if (Completed())
			{
				return;
			}

			if (_next != _current)
			{
				_current = _next;
				GraphicResouceAPI::ClearTextureData(_graphicTexture);
				auto texData = ResourceLoader::LoadTexture(FullPath(LogoCollection::files[_current]));
				_graphicTexture = GraphicResouceAPI::AddTextureData(texData);
				delete texData;
				_alpha = 0;
			}
			else
			{
				_alpha = Alpha(_time.count() / 1000.f);
			}

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
			if (Completed())
			{
				return;
			}
			GraphicResouceAPI::ClearVertexData(_graphicVertex);
			GraphicResouceAPI::ClearTextureData(_graphicTexture);
		}

		void LogoPipeline::Render()
		{
			GraphicRenderAPI::SetClear(ClearColorDepth);
			auto color = Float4(1, 1, 1, _alpha);
			GraphicRenderAPI::SetShaderProperty("_color", color);
			GraphicRenderAPI::Draw();
		}

		bool LogoPipeline::Do()
		{
			return true;
		}

		float LogoPipeline::Alpha(float time)
		{
			auto t = time - (int)(time / logoTime * 1000.f) * (logoTime / 1000.f);
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

		bool LogoPipeline::Completed()
		{
			if (!Do())
			{
				isCompleted = true;
				return true;
			}
			return false;
		}

		GraphicVertexData LogoPipeline::GenerateScreenVertex()
		{
			auto data = VertexData::CreateScreen();
			return GraphicResouceAPI::AddVertexData(data);
		}

		std::string LogoPipeline::FullPath(std::string file)
		{
			string path = "Internal/";
			path.append(file);
			return path;
		}
	}
}