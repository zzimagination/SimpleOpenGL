#ifndef __GRAPHICCOMMAND__
#define __GRAPHICCOMMAND__

#include "Graphic.h"

namespace SemperEngine
{
	namespace Core
	{		
		class GraphicCommand
		{
		public:

			GraphicCommand() {};

			virtual ~GraphicCommand() {};

			virtual void Excute() = 0;

		protected:

			void SetShaderProperty(ShaderProperty p);
		};
	}
}

#include "GraphicResouceAPI.h"
#include "GraphicRenderAPI.h"

#include "GraphicCommand/GCMD_VertexBuffer.h"
#include "GraphicCommand/GCMD_VertexBufferClear.h"
#include "GraphicCommand/GCMD_TextureBuffer.h"
#include "GraphicCommand/GCMD_TextureBufferClear.h"
#include "GraphicCommand/GCMD_ClearRecord.h"
#include "GraphicCommand/GCMD_Draw.h"
#include "GraphicCommand/GCMD_Clear.h"
#include "GraphicCommand/GCMD_Wireframe.h"
#include "GraphicCommand/GCMD_CreateRecord.h"
#include "GraphicCommand/GCMD_StopRecord.h"
#include "GraphicCommand/GCMD_ClearRecord.h"

#endif
