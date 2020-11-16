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
			GraphicRenderAPI::SetCullFace(operation.cull);
			GraphicRenderAPI::SetCullMode(operation.cullFace);
			GraphicRenderAPI::SetDepthTest(operation.depth);
			GraphicRenderAPI::SetDepthTestFunc(operation.depthFunc);
			GraphicRenderAPI::SetBlend(operation.blend);
			GraphicRenderAPI::SetBlendFunc();

			GraphicVertexData vert;
			switch (vertex.type)
			{
			case GraphicVertexInfo::Type::screen:
				vert = *GraphicDataCenter::screenVertexData.get();
				break;
			case GraphicVertexInfo::Type::custom:
				vert = *GraphicDataCenter::GetVertexData(vertex.info);
				break;
			}
			GraphicRenderAPI::SetVertexData(vert);

			SetShaderProperty(shaderProperty);
			GraphicRenderAPI::SetShaderProperty(MODEL_MATRIX, matrix.model);
			GraphicRenderAPI::SetShaderProperty(VIEW_MATRIX, matrix.view);
			GraphicRenderAPI::SetShaderProperty(PROJECTION_MARIX, matrix.projection);
			for (int i = 0; i < textures.size(); i++)
			{
				auto tex = GraphicDataCenter::GetTextureData(textures[i].info);
				GraphicRenderAPI::SetShaderProperty(textures[i].index, *tex.get());
			}

			GraphicRenderAPI::Draw();
		}

		void GDrawCMD::SetShaderProperty(ShaderProperty sproperty)
		{
			GraphicRenderAPI::SetShader(sproperty.name);
			auto fp = sproperty.floatProperty;
			for (auto i = fp.begin(); i != fp.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(i->first, i->second);
			}
			auto v2p = sproperty.vector2Property;
			for (auto i = v2p.begin(); i != v2p.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(i->first, i->second);
			}
			auto v3p = sproperty.vector3Property;
			for (auto i = v3p.begin(); i != v3p.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(i->first, i->second);
			}
			auto v4p = sproperty.vector4Property;
			for (auto i = v4p.begin(); i != v4p.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(i->first, i->second);
			}
			auto m4p = sproperty.matrix4x4Property;
			for (auto i = m4p.begin(); i != m4p.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(i->first, i->second);
			}
		}
	}
}