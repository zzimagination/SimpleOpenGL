#ifndef __GRAPHIC_RECORD__
#define __GRAPHIC_RECORD__

#include <vector>
#include "../GraphicTextureData.h"

namespace SemperEngine
{
	namespace Core
	{
		class GraphicRecord
		{
		public:

			enum class Attach
			{
				None,

				Depth,

				Stencil,

				DepthStencil
			};

		public:

			std::string name;

			int width = 0;

			int height = 0;

			Attach attach = Attach::None;

		public:

			int managerID = -1;

			unsigned int glFrameBuffer = -1;

			unsigned int glRenderBuffer = -1;

			std::vector<GraphicTextureData> textures;

		public:

			GraphicRecord();

			GraphicRecord(std::string name);
		};
	}
}
#endif // !__GRAPHIC_RECORD__
