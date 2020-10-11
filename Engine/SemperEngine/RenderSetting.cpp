#include "RenderSetting.h"
#include "GraphicCommandManager.h"

namespace SemperEngine
{
	bool RenderSetting::wireframe = false;

	void RenderSetting::SetWireframeMode(bool enable)
	{
		wireframe = enable;
		Core::GraphicCommandManager::SetWireframe(enable);
	}
}