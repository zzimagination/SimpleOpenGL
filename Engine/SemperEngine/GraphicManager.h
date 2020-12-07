#pragma once
#ifndef __GRAPHICMANAGER__
#define __GRAPHICMANAGER__

namespace SemperEngine
{
	namespace Core
	{
		class GraphicManager
		{
		public:

			static void Initialize();

			static void BeforeLoopEnd();

			static void LoopEnd();

			static void Loop();

			static void AfterLoop();

			static void Dispose();
		};
	}
}

#endif // !__GRAPHICMANAGER__
