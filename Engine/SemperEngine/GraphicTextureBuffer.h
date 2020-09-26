#pragma once
#ifndef GRAPHICCMD_TEXTUREBUFFER
#define GRAPHICCMMD_TEXTUREBUFFER

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
