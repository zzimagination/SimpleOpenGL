#ifndef __GCMD_VERTEX_BUFFER_CLEAR__
#define __GCMD_VERTEX_BUFFER_CLEAR__

#include "../GraphicCommand.h"

namespace Semper
{
	namespace Core
	{
		class GCMD_DeleteVertex : public GraphicCommand
		{
		public:

			GraphicVertexData* vertexData = nullptr;

			typedef void(*DeleteFunc)(GraphicVertexData* data);
			DeleteFunc deleteFunc = nullptr;

		public:

			GCMD_DeleteVertex(GraphicVertexData* data, DeleteFunc func);

			virtual ~GCMD_DeleteVertex() override;

			virtual void Excute() override;
		};
	}
}
#endif // !__GCMD_VERTEX_BUFFER_CLEAR__
