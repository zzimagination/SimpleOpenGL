#pragma once
#ifndef __GRAPHICCMD_TEXTUREBUFFER__
#define __GRAPHICCMD_TEXTUREBUFFER__

#include "GraphicCommand.h"

namespace SemperEngine
{
	class Texture;

	namespace Core
	{
		class GraphicTextureBuffer :public GraphicCommand
		{
		public:

			Texture* gameData;

		public:

			GraphicTextureBuffer(Texture* gameData);

			virtual void Excute() override;
		};
	}
}

#endif // !GRAPHICCMD_TEXTUREBUFFER
