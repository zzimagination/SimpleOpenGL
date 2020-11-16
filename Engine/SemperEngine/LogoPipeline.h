#pragma once
#ifndef __LOGO_PIPELINE__
#define __LOGO_PIPELINE__

#include <chrono>
#include <memory>
#include "Texture.h"
#include "Material.h"

namespace SemperEngine
{
	namespace Core
	{
		class LogoPipeline
		{
		public:

			static float logoTime;

			static std::vector<std::shared_ptr<Texture>> logoTextures;

			static std::shared_ptr<Material> material;

			static bool isCompleted;

		private:

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

			static void LoadResources();

			static void Dispose();

			static void Render();

			static bool Do();

			static float Alpha(float time);
		};
	}
}

#endif // !LOGO_PIPELINE
