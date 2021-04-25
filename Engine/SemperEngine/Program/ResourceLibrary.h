#pragma once
#ifndef __RESOURCE_LIBRARY__
#define __RESOURCE_LIBRARY__

#include <memory>
#include <string>
#include <list>
#include <type_traits>
#include "Common.h"
#include "ResourceObject.h"

namespace Semper
{
	namespace Core
	{
		template<class T>
		class ResourceLibrary
		{
		protected:

			FillList<T*> _library;

		public:

			ResourceLibrary() {}

			virtual ~ResourceLibrary() {}

			void DisposeUnuse()
			{
				static_assert(std::is_base_of<ResourceObject, T>().value);
				for (int i = 0; i < (int)_library.Size(); i++)
				{
					if (_library.IsEmpty(i))
					{
						continue;
					}
					if (_library[i]->useCount == 1)
					{
						_library[i]->Dispose();
						_library.Remove(i);
					}
				}
			}

		};
	}
}

#endif // !__RESOURCE_LIBRARY__
