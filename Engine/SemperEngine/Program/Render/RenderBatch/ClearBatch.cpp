#include "ClearBatch.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

		ClearBatch::ClearBatch()
		{
			clearColor = Color(Float3(1, 1, 1));
			clearMode = ClearColorDepth;
		}

		ClearBatch::ClearBatch(Color color, Graphic::ClearMode mode) : clearColor(color), clearMode(mode)
		{
		}

		ClearBatch::~ClearBatch()
		{
		}

		void ClearBatch::RenderGraphicObject()
		{
			GraphicRenderer::Clear(clearColor, clearMode);
		}

		void ClearBatch::GenerateGraphicResource()
		{
		}
	}
}