#ifndef __GCMD_CREATE_VERTEX__
#define __GCMD_CREATE_VERTEX__

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

			virtual void Execute() override;
		};
	}
}
#endif // !__GCMD_CREATE_VERTEX__
