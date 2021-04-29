#ifndef __GRAPHICCOMMAND__
#define __GRAPHICCOMMAND__

#include <memory>
#include "Graphic.h"
#include "GraphicData.h"
#include "GraphicRecord.h"
#include "GraphicResouceAPI.h"
#include "GraphicRenderAPI.h"

namespace Semper
{
	namespace Core
	{
		class GraphicCommand
		{
		public:

			GraphicCommand() {};

			virtual ~GraphicCommand() {};

			virtual void Execute() = 0;

		protected:

		};
	}
}

#include "GraphicCommand/GCMD_CreateVertex.h"
#include "GraphicCommand/GCMD_DeleteVertex.h"
#include "GraphicCommand/GCMD_CreateTexture.h"
#include "GraphicCommand/GCMD_DeleteTexture.h"
#include "GraphicCommand/GCMD_Draw.h"
#include "GraphicCommand/GCMD_Clear.h"
#include "GraphicCommand/GCMD_Wireframe.h"
#include "GraphicCommand/GCMD_CreateRecord.h"
#include "GraphicCommand/GCMD_StartRecord.h"
#include "GraphicCommand/GCMD_StopRecord.h"
#include "GraphicCommand/GCMD_DeleteRecord.h"
#include "GraphicCommand/GCMD_DefaultFrameBuffer.h"

#endif
