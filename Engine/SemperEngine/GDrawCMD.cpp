#include "GraphicCommand.h"
#include "GraphicDataCenter.h"
#include "GraphicRenderAPI.h"
#include "GraphicShaderManager.h"
#include "CubeData.h"
#include "GLRendererAPI.h"

namespace SemperEngine
{
	namespace Core
	{
		GDrawCMD::GDrawCMD(std::shared_ptr<Vertex> v, Matrix4x4 m, Matrix4x4 view, Matrix4x4 p, std::string shader, ShaderProperty& pro)
		{
			this->vertexData = v;
			this->modelMatrix = m;
			this->viewMatrix = view;
			this->projectionMatrix = p;
			this->shader = shader;
			this->shaderProperty = pro;
		}

		GDrawCMD::~GDrawCMD()
		{
		}

		void GDrawCMD::Excute()
		{
			GraphicRenderAPI::SetCullMode(1);
			GraphicRenderAPI::SetCullFace(true);
			GraphicRenderAPI::SetCullMode(3);
			GraphicRenderAPI::SetDepthTest(true);

			GraphicRenderAPI::SetVertexData(vertexData.lock()->graphicData);
			GraphicRenderAPI::SetTransform(modelMatrix, viewMatrix, projectionMatrix);
			GraphicRenderAPI::SetShader(shader);
			GraphicRenderAPI::SetShaderProperty(shaderProperty);
			GraphicRenderAPI::Draw();
		}
	}
}