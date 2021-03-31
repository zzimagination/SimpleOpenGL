#ifndef __GCMD_VERTEX_BUFFER_CLEAR__
#define __GCMD_VERTEX_BUFFER_CLEAR__

#include "../GraphicCommand.h"

namespace SemperEngine
{
	namespace Core
	{
		class GVertexBufferClearCMD : public GraphicCommand
		{
		public:

			GraphicDataInfo dataInfo;

		public:

			GVertexBufferClearCMD(GraphicDataInfo info);

			virtual ~GVertexBufferClearCMD() override;

			virtual void Excute() override;
		};
	}
}
#endif // !__GCMD_VERTEX_BUFFER_CLEAR__
