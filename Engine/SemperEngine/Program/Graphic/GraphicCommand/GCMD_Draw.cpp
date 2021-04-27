#include "GCMD_Draw.h"
#include "../GraphicResource.h"
#include "../GraphicRecordManager.h"
#include "../GraphicShaderManager.h"

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

		void GDrawCMD::Execute()
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
			auto shader = GraphicShaderManager::GetShader(shaderProperty.shaderID);
			int count = 0;
			UseRecords(count);
			for (size_t i = 0; i < textureData.size(); i++)
			{
				auto tex = textureData[i];
				GraphicRenderAPI::SetShaderProperty(shader, (int)i + count, tex);
			}
		}

		void GDrawCMD::UseRecords(int &count)
		{
		}

	}
}