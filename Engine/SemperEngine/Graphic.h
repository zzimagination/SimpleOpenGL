#pragma once
#ifndef __GRAPHIC__
#define __GRAPHIC__

#include <memory>

namespace SemperEngine
{
	namespace Core
	{
		struct GraphicDataInfo
		{
			int index = -1;
		};

		struct GraphicTextureInfo
		{
			int index = -1;

			GraphicDataInfo info;
		};

		struct GraphicVertexInfo
		{
			enum struct Type
			{
				custom,
				screen
			};

			Type type = Type::custom;

			GraphicDataInfo info;
		};
	}
}

#endif // !__GRAPHIC__
