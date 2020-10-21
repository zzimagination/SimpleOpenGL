#include "GraphicCommand.h"
#include "GraphicDataCenter.h"
#include "GraphicRenderAPI.h"
#include "GraphicShaderManager.h"
#include "CubeData.h"
#include "GLRendererAPI.h"
#include "ShaderProperty.h"

namespace SemperEngine
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
			GraphicRenderAPI::SetCullMode(1);
			GraphicRenderAPI::SetCullFace(true);
			GraphicRenderAPI::SetDepthTest(true);

			GraphicRenderAPI::SetVertexData(vertexData->graphicData);
			GraphicRenderAPI::SetShader(shader);
			GraphicRenderAPI::SetShaderProperty(MODEL_MATRIX, modelMatrix);
			GraphicRenderAPI::SetShaderProperty(VIEW_MATRIX, viewMatrix);
			GraphicRenderAPI::SetShaderProperty(PROJECTION_MARIX, projectionMatrix);
			for (int i = 0; i < floatNames.size(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(floatNames[i], floatValues[i]);
			}
			for (int i = 0; i < vec2Names.size(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(vec2Names[i], vec2Values[i]);
			}
			for (int i = 0; i < vec3Names.size(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(vec3Names[i], vec3Values[i]);
			}
			for (int i = 0; i < vec4Names.size(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(vec4Names[i], vec4Values[i]);
			}
			for (int i = 0; i < mat4Names.size(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(mat4Names[i], mat4Values[i]);
			}
			for (int i = 0; i < textureData.size(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(i, textureData[i]->graphicData);
			}
			GraphicRenderAPI::Draw();
		}
	}
}