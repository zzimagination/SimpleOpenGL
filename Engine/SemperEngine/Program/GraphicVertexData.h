#pragma once
#ifndef __GRAPHICVERTEXDATA__
#define __GRAPHICVERTEXDATA__

#include "GraphicData.h"
#include "Graphic.h"

namespace SemperEngine
{
	namespace Core
	{
		class GraphicVertexData : public GraphicData
		{
		public:

			unsigned int VAO = 0;

			unsigned int VBO = 0;

			unsigned int EBO = 0;

			bool indexDraw = false;

			int pointCount = 0;

			GraphicVertexResource source;

		public:

			GraphicVertexData();

			GraphicVertexData(unsigned int vao, unsigned int vbo, int pointCount);

			GraphicVertexData(unsigned int vao, unsigned int vbo, unsigned int ebo, int pointCount);

			virtual ~GraphicVertexData() override;
		};
	}
}
#endif // !__GRAPHICVERTEXDATA__
