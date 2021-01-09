#pragma once
#ifndef __RESOURCE_LIBRARY__
#define __RESOURCE_LIBRARY__

#include <memory>
#include <string>
#include <list>
#include <type_traits>
#include "Common.h"
#include "ResourceObject.h"

namespace SemperEngine
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
					if (!_library[i].usable)
					{
						continue;
					}
					if (_library[i].value->useCount == 1)
					{
						_library[i].value->Dispose();
						_library.Remove(i);
					}
				}
			}

		};
	}
}

#endif // !__RESOURCE_LIBRARY__
