#include "TextureObject.h"

namespace SemperEngine
{
	namespace Core
	{
		TextureObject::TextureObject()
		{
		}
		TextureObject::TextureObject(bool share) :ResourceObject(share)
		{
		}
		TextureObject::TextureObject(bool share, Setting setting) : ResourceObject(share)
		{
			readOnly = setting.readOnly;
		}
		TextureObject::~TextureObject()
		{
		}
	}
}