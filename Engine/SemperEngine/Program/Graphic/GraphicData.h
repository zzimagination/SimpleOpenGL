#ifndef __GRAPHIC_RESOURCE__
#define __GRAPHIC_RESOURCE__

#include <vector>
#include <memory>
#include "Graphic.h"

namespace SemperEngine
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

#include "Data/GraphicVertexData.h"
#include "Data/GraphicTextureData.h"

#endif // !__GRAPHIC_RESOURCE__
