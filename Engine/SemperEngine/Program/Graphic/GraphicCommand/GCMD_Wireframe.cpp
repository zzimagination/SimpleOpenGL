#include "GCMD_Wireframe.h"

namespace SemperEngine
{
	namespace Core
	{
		GWireframeCMD::GWireframeCMD(bool enable)
		{
			this->enable = enable;
		}

		GWireframeCMD::~GWireframeCMD()
		{
		}

		void GWireframeCMD::Excute()
		{
			GraphicRenderAPI::SetWireframe(enable);
		}
	}
}