#include "GCMD_Draw.h"
#include "../GraphicResource.h"
#include "../GraphicRecordManager.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

		GDrawCMD::GDrawCMD()
		{
		}

		GDrawCMD::~GDrawCMD()
		{
		}

		void GDrawCMD::Excute()
		{
			GraphicRenderAPI::SetCullFace(operation.cull);
			GraphicRenderAPI::SetCullMode(operation.cullFace);
			GraphicRenderAPI::SetDepthTest(operation.depth);
			GraphicRenderAPI::SetDepthTestFunc(operation.depthFunc);
			GraphicRenderAPI::SetBlend(operation.blend);
			GraphicRenderAPI::SetBlendFunc();

			GraphicRenderAPI::SetVertexData(vertexData);
			SetShaderProperty(shaderProperty);
			SetTextures();
			GraphicRenderAPI::Draw(vertexData);
		}

		void GDrawCMD::SetTextures()
		{
			int count = 0;
			UseRecords(count);
			for (size_t i = 0; i < textureData.size(); i++)
			{
				auto tex = textureData[i];
				GraphicRenderAPI::SetShaderProperty((int)i + count, tex);
			}
		}

		void GDrawCMD::UseRecords(int &count)
		{
		}

	}
}