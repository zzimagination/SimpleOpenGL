#include "DefaultFrameBufferSection.h"
#include "../RenderRecordManager.h"
#include "../../Graphic/GraphicRenderer.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

		void DefaultFramebufferSection::Start()
		{
			auto record = RenderRecordManager::GetRecord(key, camera);
			GraphicRenderer::DefaultFrameBuffer(record.graphicID);
		}
	}
}

