#include "MaterialObject.h"
#include "Graphic/GraphicShaderManager.h"

namespace Semper
{
	namespace Core
	{
		MaterialObject* MaterialObject::Create(std::string shader)
		{
			auto object = new MaterialObject;
			object->shaderName = shader;
			object->shaderID = GraphicShaderManager::GetShaderID(shader);
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
			for (auto i = textureProperties.begin(); i != textureProperties.end(); i++)
			{
				auto obj = (TextureObject*)i->second->GetObject();
				obj->CreateGraphicResource();
			}
		}

		void MaterialObject::DeleteGraphicResource()
		{
		}
	}
}