#ifndef __GCMD_VERTEX_BUFFER__
#define __GCMD_VERTEX_BUFFER__

#include "../GraphicCommand.h"

namespace Semper
{
	namespace Core
	{
		class GCMD_CreateVertex : public GraphicCommand
		{
		public:

			GraphicVertexData* vertexData = nullptr;

		public:

			GCMD_CreateVertex(GraphicVertexData* data);

			virtual ~GCMD_CreateVertex() override;

			virtual void Excute() override;
		};
	}
}
#endif // !__GCMD_VERTEX_BUFFER__
