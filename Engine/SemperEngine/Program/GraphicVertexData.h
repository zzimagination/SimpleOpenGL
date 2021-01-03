#pragma once
#ifndef __GRAPHICVERTEXDATA__
#define __GRAPHICVERTEXDATA__

#include "GraphicData.h"
#include "VertexData.h"

namespace SemperEngine
{
	namespace Core
	{
		class GraphicVertexData : public GraphicData
		{
		public:

			unsigned int VAO;

			unsigned int VBO;

			unsigned int EBO;

			int pointCount;

		private:

			VertexData* _source = nullptr;

		public:

			GraphicVertexData();

			GraphicVertexData(unsigned int vao, unsigned int vbo, unsigned int ebo, int pointCount);

			virtual ~GraphicVertexData() override;

			void SetSource(VertexData* source);

			VertexData* GetSource();

			virtual void Complete() override;
		};
	}
}
#endif // !__GRAPHICVERTEXDATA__
