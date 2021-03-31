#pragma once
#ifndef __LOGO_PIPELINE__
#define __LOGO_PIPELINE__

#include <memory>
#include "LogoCollection.h"
#include "RenderScreenObject.h"
#include "Graphic/GraphicData.h"

namespace SemperEngine
{
	namespace Core
	{
		class LogoPipeline
		{
		public:

			static float logoFrame;

			static bool isCompleted;

		private:

			static std::shared_ptr<RenderScreenObject> _renderObject;

			static int _total;

			static int _current;

			static int _next;

			static float _alpha;

			static int _frame;

			static std::vector<std::shared_ptr<Texture>> _logoTextures;

		public:

			static void Start();

			static void Update();

			static void End();

		private:

			static void LoadResource();

			static void Resource();

			static void Render();

			static float Alpha(float time);

		};
	}
}

#endif // !LOGO_PIPELINE
