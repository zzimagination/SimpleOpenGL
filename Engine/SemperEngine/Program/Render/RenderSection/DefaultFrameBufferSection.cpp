#include "DefaultFrameBufferSection.h"
#include "../RenderRecordManager.h"
#include "../../Graphic/GraphicRenderer.h"

namespace SemperEngine
{
	namespace Core
	{
		void DefaultFramebufferSection::Prepare()
		{
		}

		void DefaultFramebufferSection::Start()
		{
			auto r = RenderRecordManager::GetGraphicRecord(RenderRecord(camera, record));
			GraphicRenderer::DefaultFrameBuffer(r);
		}
	}
}

