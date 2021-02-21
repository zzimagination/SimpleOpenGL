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
