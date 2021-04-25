#pragma once
#ifndef __RESOURCEOBJECTCENTER__
#define __RESOURCEOBJECTCENTER__

#include <memory>
#include <vector>
#include "ResourceObject.h"

namespace Semper
{
	namespace Core
	{
		class ResourceObjectCenter
		{
		public:

			static std::vector<ResourceObject*> _newObjects;

			static std::vector<ResourceObject*> _deleteObjects;

			static std::vector<ResourceObject*> _modifyObjects;

		public:

			static void EndProcess();

			static void Create(ResourceObject* obj);

			static void Delete(ResourceObject* obj);

			static void Modify(ResourceObject* obj);

		};
	}
}

#endif // !__RESOURCEOBJECTCENTER__
