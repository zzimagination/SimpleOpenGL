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
			SetShaderProperty();
			GraphicRenderAPI::Draw(vertexData);
		}

		void GDrawCMD::SetShaderProperty()
		{
			auto shader = GraphicShaderManager::GetShader(shaderProperty->shaderID);
			GraphicRenderAPI::UseShader(shader);
			for (auto i = shaderProperty->floatProperty.begin(); i != shaderProperty->floatProperty.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(shader, i->first, i->second);
			}
			for (auto i = shaderProperty->vector2Property.begin(); i != shaderProperty->vector2Property.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(shader, i->first, i->second);
			}
			for (auto i = shaderProperty->vector3Property.begin(); i != shaderProperty->vector3Property.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(shader, i->first, i->second);
			}
			for (auto i = shaderProperty->vector4Property.begin(); i != shaderProperty->vector4Property.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(shader, i->first, i->second);
			}
			for (auto i = shaderProperty->colorProperty.begin(); i != shaderProperty->colorProperty.end(); i++)
			{
				auto f = i->second.ToFloat4();
				GraphicRenderAPI::SetShaderProperty(shader, i->first, f);
			}
			for (auto i = shaderProperty->matrix4x4Property.begin(); i != shaderProperty->matrix4x4Property.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(shader, i->first, i->second);
			}

			int texCount = 0;
			for (auto i = shaderProperty->textureProperty.begin(); i < shaderProperty->textureProperty.end(); i++)
			{
				auto tex = GraphicResource::GetTexture(*i);
				GraphicRenderAPI::SetShaderProperty(shader, texCount, tex);
				texCount++;
			}
			UseRecords(texCount);
		}

		void GDrawCMD::UseRecords(int &count)
		{
		}

	}
}