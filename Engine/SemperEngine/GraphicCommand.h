#pragma once
#ifndef GRAPHICCOMMAND
#define GRAPHICCOMMAND

#include <vector>
#include <memory>
#include "Mathz.h"

namespace SemperEngine
{
	namespace Core
	{
		class GraphicCommand
		{
		public:

			virtual void Excute() = 0;
		};
	}
}

#include "GraphicVertexBuffer.h"
#include "GraphicVertexBufferClear.h"
#include "GraphicDraw.h"

#endif