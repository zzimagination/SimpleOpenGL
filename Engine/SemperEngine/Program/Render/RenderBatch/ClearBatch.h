#ifndef __CLEAR_RENDERBATCH__
#define __CLEAR_RENDERBATCH__

#include "../RenderBatch.h"

namespace SemperEngine
{
	namespace Core
	{
		class ClearBatch : public RenderBatch
		{
		public:

			Color clearColor;

			Graphic::ClearMode clearMode;

		public:

			ClearBatch();

			ClearBatch(Color color, Graphic::ClearMode mode);

			virtual ~ClearBatch() override;

			virtual void RenderGraphicObject() override;

			virtual void GenerateGraphicResource() override;
		};
	}
}
#endif // !__CLEAR_RENDERBATCH__