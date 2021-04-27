#include "GCMD_Clear.h"

namespace Semper
{
	namespace Core
	{
		GCMD_Clear::GCMD_Clear(Color color, Graphic::ClearMode mode)
		{
			this->color = color;
			this->mode = mode;
		}

		GCMD_Clear::~GCMD_Clear()
		{
		}

		void GCMD_Clear::Execute()
		{
			GraphicRenderAPI::SetClearColor(color);
			GraphicRenderAPI::SetClear(mode);
		}
	}
}