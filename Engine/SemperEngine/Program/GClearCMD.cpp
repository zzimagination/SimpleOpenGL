#include "GraphicCommand.h"
#include "GraphicRenderAPI.h"

namespace SemperEngine
{
	namespace Core
	{
		GClearCMD::GClearCMD(Color color, Graphic::ClearMode mode)
		{
			this->color = color;
			this->mode = mode;
		}

		GClearCMD::~GClearCMD()
		{
		}

		void GClearCMD::Excute()
		{
			GraphicRenderAPI::SetClearColor(color);
			GraphicRenderAPI::SetClear(mode);
		}
	}
}