#include "ResourceObject.h"
#include "ResourceObjectCenter.h"

namespace SemperEngine
{
	namespace Core
	{
		ResourceObject::ResourceObject()
		{
		}
		ResourceObject::~ResourceObject()
		{
		}
		int ResourceObject::Use()
		{
			useCount++;
			if (useCount == 1)
			{
				ResourceObjectCenter::Create(this);
			}
			return useCount;
		}

		int ResourceObject::Dispose()
		{
			useCount--;
			if (useCount == 0)
			{
				ResourceObjectCenter::Delete(this);
			}
			return useCount;
		}

		void ResourceObject::Modify()
		{
			ResourceObjectCenter::Modify(this);
		}

		void ResourceObject::EndCreate()
		{
		}

		void ResourceObject::EndDelete()
		{
		}

		void ResourceObject::EndModify()
		{
		}
	}
}