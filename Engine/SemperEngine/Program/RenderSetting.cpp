#include "RenderSetting.h"
#include "GraphicRenderer.h"

namespace SemperEngine
{
	using namespace Core;

	bool RenderSetting::wireframe = false;

	void RenderSetting::SetWireframeMode(bool enable)
	{
		wireframe = enable;
		GraphicRenderer::Wireframe(wireframe);
	}
}