#include "GraphicCommand.h"
#include "GraphicDataCenter.h"
#include "GraphicRenderAPI.h"

namespace SemperEngine
{
	namespace Core
	{
		GDrawScreen::GDrawScreen()
		{
		}

		GDrawScreen::~GDrawScreen()
		{
		}

		void GDrawScreen::Excute()
		{
			GraphicRenderAPI::SetDepthTest(false);
			GraphicRenderAPI::SetBlend(true);
			GraphicRenderAPI::SetBlendFunc();
			GraphicRenderAPI::SetVertexData(vertexData);
			GraphicRenderAPI::SetShader(shader);
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

		void GDrawScreen::SetShaderProperty(std::shared_ptr<Material> material)
		{
			shader = material->shader;
			auto fp = &material->shaderProperty.floatProperty;
			for (auto i = fp->begin(); i != fp->end(); i++)
			{
				floatNames.push_back(i->first);
				floatValues.push_back(i->second);
			}
			auto v2p = &material->shaderProperty.vector2Property;
			for (auto i = v2p->begin(); i != v2p->end(); i++)
			{
				vec2Names.push_back(i->first);
				vec2Values.push_back(i->second);
			}
			auto v3p = &material->shaderProperty.vector3Property;
			for (auto i = v3p->begin(); i != v3p->end(); i++)
			{
				vec3Names.push_back(i->first);
				vec3Values.push_back(i->second);
			}
			auto v4p = &material->shaderProperty.vector4Property;
			for (auto i = v4p->begin(); i != v4p->end(); i++)
			{
				vec4Names.push_back(i->first);
				vec4Values.push_back(i->second);
			}
			auto m4p = &material->shaderProperty.matrix4x4Property;
			for (auto i = m4p->begin(); i != m4p->end(); i++)
			{
				mat4Names.push_back(i->first);
				mat4Values.push_back(i->second);
			}
			auto textureProperty = &material->shaderProperty.textureProperty;
			for (auto i = textureProperty->begin(); i != textureProperty->end(); i++)
			{
				auto id = i->first;
				auto tex = i->second;
				auto data = GraphicDataCenter::GetTextureCommandData(tex->Package());
				textureData.push_back(data);
			}
		}
	}
}