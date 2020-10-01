#pragma once
#ifndef GRAPHICCMD_BUFFER
#define GRAPHICCMD_BUFFER

#include "GraphicCommand.h"
#include "GraphicCommandData.h"

namespace SemperEngine
{

	namespace Core
	{
		class GVertexBufferCMD : public GraphicCommand
		{
		public:

			std::shared_ptr<Vertex> data;

		public:

			GVertexBufferCMD(std::shared_ptr<Vertex> data);

			virtual void Excute() override;
;
		};
	}
}

#endif // !GRAPHICCMD_BUFFER
