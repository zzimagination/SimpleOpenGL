#ifndef __GRAPHIC_RESOURCE__
#define __GRAPHIC_RESOURCE__

#include <vector>
#include <memory>
#include "Graphic.h"

namespace Semper
{
	namespace Core
	{
		class GraphicData
		{
		public:

			std::string name;

			bool isPrimitived = true;

		public:

			GraphicData() {};

			virtual ~GraphicData() {};

			virtual void Complete() { isPrimitived = false; };
		};
	}
}
#endif // !__GRAPHIC_RESOURCE__

#include "GraphicVertexData.h"
#include "GraphicTextureData.h"