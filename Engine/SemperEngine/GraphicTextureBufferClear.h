#pragma once
#ifndef GRAPHICCMD_TEXTUREBUFFERCLEAR
#define GRAPHICCMD_TEXTUREBUFFERCLEAR

#include "GraphicCommand.h"

namespace SemperEngine
{
	class Texture;

	namespace Core
	{
		class GraphicTextureBufferClear : public GraphicCommand
		{
		public:

			Texture* gameData;

		public:

			GraphicTextureBufferClear(Texture* gameData);

			virtual void Excute() override;
		};
	}
}


#endif // !GRAPHICCMD_TEXTUREBUFFERCLEAR
