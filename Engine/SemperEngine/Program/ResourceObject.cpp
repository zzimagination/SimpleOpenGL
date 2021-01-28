#include "ResourceObject.h"
#include "ResourceObjectCenter.h"
#include "Debug.h"

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
			if (used == false)
			{
				used = true;
				ResourceObjectCenter::Create(this);
			}
			OnUse();
			return useCount;
		}

		int ResourceObject::Dispose()
		{
			if (!used)
			{
				Debug::LogError("Haven't used");
				return 0;
			}

			useCount--;
			OnDispose();
			if (useCount <= 0)
			{
				used = false;
				Delete();
				ResourceObjectCenter::Delete(this);
			}
			return useCount;
		}

		void ResourceObject::Modify()
		{
			ResourceObjectCenter::Modify(this);
		}

		void ResourceObject::OnUse()
		{
		}

		void ResourceObject::OnDispose()
		{
		}

		void ResourceObject::Delete()
		{
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