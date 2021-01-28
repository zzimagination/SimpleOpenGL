#include "MaterialObject.h"

namespace SemperEngine
{
	namespace Core
	{
		MaterialObject* MaterialObject::Create()
		{
			auto object = new MaterialObject;
			return object;
		}
		MaterialObject::~MaterialObject()
		{
		}
		MaterialObject* MaterialObject::Copy()
		{
			return nullptr;
		}
	}
}