#pragma once
#ifndef __LOGO_PIPELINE__
#define __LOGO_PIPELINE__

#include <chrono>
#include <memory>
#include "GraphicVertexData.h"
#include "GraphicTextureData.h"

namespace SemperEngine
{
	namespace Core
	{
		class LogoPipeline
		{
		public:

			static float logoTime;

			static bool isCompleted;

		private:

			static GraphicVertexData _graphicVertex;

			static GraphicTextureData _graphicTexture;

			static int _current;

			static int _next;

			static float _alpha;

			static std::chrono::milliseconds _time;

			static std::chrono::time_point<std::chrono::system_clock> _startTime;

		public:

			static void Start();

			static void Update();

			static void End();

		private:

			static void Render();

			static bool Do();

			static float Alpha(float time);

			static bool Completed();

			static GraphicVertexData GenerateScreenVertex();

			static std::string FullPath(std::string file);
		};
	}
}

#endif // !LOGO_PIPELINE
