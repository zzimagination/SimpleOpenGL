#pragma once
#ifndef __LOGO_PIPELINE__
#define __LOGO_PIPELINE__

#include <chrono>
#include <memory>
#include "GraphicVertexData.h"
#include "GraphicTextureData.h"
#include "RenderScreenObject.h"

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

			static std::shared_ptr<RenderScreenObject> _renderObject;

			static int _current;

			static int _next;

			static float _alpha;

			static std::chrono::milliseconds _time;

			static std::chrono::time_point<std::chrono::system_clock> _startTime;

			static std::vector<std::shared_ptr<Texture>> _logoTextures;

		public:

			static void Start();

			static void Update();

			static void End();

		private:

			static void Resource();

			static void Render();

			static float Alpha(float time);

		};
	}
}

#endif // !LOGO_PIPELINE
