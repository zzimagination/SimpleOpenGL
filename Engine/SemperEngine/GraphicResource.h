#pragma once
#ifndef __GRAPHIC_RESOURCE__
#define __GRAPHIC_RESOURCE__

#include <vector>
#include "Mathz.h"

namespace SemperEngine
{
	namespace Core
	{
		class GraphicResource
		{
		public:

			GraphicResource() {};

			virtual ~GraphicResource() {};
		};

		class GraphicVertexData : public GraphicResource
		{
		public:

			unsigned int VAO;

			unsigned int VBO;

			unsigned int EBO;

			int pointCount;

		public:

			GraphicVertexData();

			GraphicVertexData(unsigned int vao, unsigned int vbo, unsigned int ebo, int pointCount);

			virtual ~GraphicVertexData() override;
		};

		class GraphicTextureData : public GraphicResource
		{

		public:

			unsigned int glid;

		public:

			GraphicTextureData();

			GraphicTextureData(int id);

			virtual ~GraphicTextureData() override;
		};
	}
}

#endif // !__GRAPHIC_RESOURCE__
