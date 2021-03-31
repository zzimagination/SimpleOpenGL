#ifndef __GCMD_VERTEX_BUFFER__
#define __GCMD_VERTEX_BUFFER__

#include "../GraphicCommand.h"

namespace SemperEngine
{
	namespace Core
	{
		class GVertexBufferCMD : public GraphicCommand
		{
		public:

			GraphicDataInfo dataInfo;

		public:

			GVertexBufferCMD(GraphicDataInfo info);

			virtual ~GVertexBufferCMD() override;

			virtual void Excute() override;
		};
	}
}
#endif // !__GCMD_VERTEX_BUFFER__
