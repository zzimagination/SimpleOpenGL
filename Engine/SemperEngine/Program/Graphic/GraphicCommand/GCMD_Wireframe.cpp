#include "GCMD_Wireframe.h"

namespace Semper
{
	namespace Core
	{
		GCMD_Wireframe::GCMD_Wireframe(bool enable)
		{
			this->enable = enable;
		}

		GCMD_Wireframe::~GCMD_Wireframe()
		{
		}

		void GCMD_Wireframe::Execute()
		{
			GraphicRenderAPI::SetWireframe(enable);
		}
	}
}