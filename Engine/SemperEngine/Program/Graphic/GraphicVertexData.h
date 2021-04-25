#ifndef __GRAPHICVERTEXDATA__
#define __GRAPHICVERTEXDATA__

#include "GraphicData.h"

namespace Semper
{
	namespace Core
	{
		class GraphicVertexData : public GraphicData
		{
		public:

			GraphicVertexResource source;

		public:

			unsigned int VAO = 0;

			unsigned int VBO = 0;

			unsigned int EBO = 0;

			int pointCount = 0;

		public:

			GraphicVertexData();

			virtual ~GraphicVertexData() override;

			void SetGL(unsigned int VAO, unsigned int VBO, int pointCount);

			void SetGL(unsigned int VAO, unsigned int VBO, unsigned int EBO, int pointCount);
		};
	}
}
#endif // !__GRAPHICVERTEXDATA__
