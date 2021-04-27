#include "MaterialObject.h"
#include "Graphic/GraphicShaderManager.h"

namespace Semper
{
	namespace Core
	{
		MaterialObject* MaterialObject::Create(std::string shader)
		{
			auto object = new MaterialObject;
			object->shaderProperty.shaderID = GraphicShaderManager::GetShaderID(shader);
			return object;
		}

		MaterialObject::~MaterialObject()
		{
		}

		MaterialObject* MaterialObject::Copy()
		{
			return nullptr;
		}

		void MaterialObject::CreateGraphicResource()
		{
			for (auto tex = textures.begin(); tex != textures.end(); tex++)
			{
				auto graphicResource = (TextureObject*)tex->get()->GetObject();
				graphicResource->CreateGraphicResource();
			}
		}

		void MaterialObject::DeleteGraphicResource()
		{
		}
	}
}