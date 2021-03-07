#include "RenderRecordManager.h"
#include "../GraphicRenderer.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		void RenderRecordManager::CreateRecord(string name)
		{
			GraphicRenderer::CreateRecord(name);
		}
		void RenderRecordManager::StopRecord()
		{
			GraphicRenderer::StopRecord();
		}
	}
}