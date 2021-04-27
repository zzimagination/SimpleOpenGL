#include "GraphicCommand.h"
#include "GraphicShaderManager.h"

namespace Semper
{
	namespace Core
	{
		void GraphicCommand::SetShaderProperty(ShaderProperty& p)
		{
			auto shader = GraphicShaderManager::GetShader(p.shaderID);
			GraphicRenderAPI::UseShader(shader);
			for (auto i = p.floatProperty.begin(); i != p.floatProperty.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(shader, i->first, i->second);
			}
			for (auto i = p.vector2Property.begin(); i != p.vector2Property.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(shader, i->first, i->second);
			}
			for (auto i = p.vector3Property.begin(); i != p.vector3Property.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(shader, i->first, i->second);
			}
			for (auto i = p.vector4Property.begin(); i != p.vector4Property.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(shader, i->first, i->second);
			}
			for (auto i = p.colorProperty.begin(); i != p.colorProperty.end(); i++)
			{
				auto f = i->second.ToFloat4();
				GraphicRenderAPI::SetShaderProperty(shader, i->first, f);
			}
			for (auto i = p.matrix4x4Property.begin(); i != p.matrix4x4Property.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(shader, i->first, i->second);
			}
		}
	}
}