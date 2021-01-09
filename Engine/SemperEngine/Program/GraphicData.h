#pragma once
#ifndef __GRAPHIC_RESOURCE__
#define __GRAPHIC_RESOURCE__

#include <vector>
#include <memory>
#include "Common.h"

namespace SemperEngine
{
	namespace Core
	{
		class GraphicData
		{
		public:

			bool isPrimitived = true;

		public:

			GraphicData() {};

			virtual ~GraphicData() {};

			virtual void Complete() {};
		};
	}
}

#endif // !__GRAPHIC_RESOURCE__
