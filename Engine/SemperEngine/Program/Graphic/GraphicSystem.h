#ifndef __GRAPHICMANAGER__
#define __GRAPHICMANAGER__

namespace Semper
{
	namespace Core
	{
		class GraphicSystem
		{
		public:

			static void Initialize();

			static void Render();

			static void Resource();

			static void SwapCommands();

			static void Dispose();
		};
	}
}

#endif // !__GRAPHICMANAGER__
