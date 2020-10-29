#pragma once
#ifndef __RESOURCE_PACKAGE__
#define __RESOURCE_PACKAGE__

#include<memory>
#include <type_traits>
#include "ObjectIndex.h"

namespace SemperEngine
{
	namespace Core
	{
		typedef ObjectIndex GPUResourceID;

		typedef unsigned int ResourceID;

		template<class T>
		class IPackage;

		template<class T>
		class ResourcePackage
		{
		public:

			GPUResourceID gid;

			ResourceID id;

			typedef void (*OnDestroy)(ResourceID);

			OnDestroy onDestroy;

		private:

			T* _data;

			void* _user;

			std::shared_ptr<bool> _isEmpty;

			std::shared_ptr<int> _useCount;

		public:

			ResourcePackage()
			{
				_useCount = std::shared_ptr<int>(new int(0));
				_isEmpty = std::shared_ptr<bool>(new bool(true));
			}

			ResourcePackage(T* resource)
			{
				std::is_base_of<IPackage<T>, T>();
				if (resource == nullptr)
				{
					throw "NULL";
				}
				_data = resource;
				_useCount = std::shared_ptr<int>(new int(0));
				_isEmpty = std::shared_ptr<bool>(new bool(false));
			}

			~ResourcePackage()
			{
			}

			T* GetResource()
			{
				if (IsEmpty())
				{
					throw "have destroy";
				}
				return _data;
			}

			void Use()
			{
				if (IsEmpty())
				{
					throw "have destroy";
				}
				auto count = *_useCount;
				*_useCount = *_useCount + 1;
				if (count == 0)
				{
					_data->Package(*this);
				}
			}

			void Use(void* user)
			{
				if (user == _user)
				{
					return;
				}
				else if (_user != nullptr)
				{
					throw "have user";
				}
				Use();
				_user = user;
			}

			void Dispose(void* user)
			{
				if (user != _user)
				{
					throw "error user";
				}
				Dispose();
			}

			void Dispose()
			{
				if (IsEmpty())
				{
					return;
				}
				*_useCount = *_useCount - 1;
				if (*_useCount < 0)
				{
					throw "have destroied";
				}
				if (*_useCount == 0)
				{
					Destory();
				}
			}

			int UseCount()
			{
				return *_useCount;
			}

			bool IsEmpty()
			{
				return *_isEmpty;
			}

		private:

			void Destory()
			{
				delete _data;
				*_isEmpty = true;
				if (onDestroy != nullptr)
				{
					onDestroy(id);
				}
			}
		};

		template<class T>
		class IPackage
		{
		public:

			virtual void Package(ResourcePackage<T> mine) = 0;
		};

	}
}

#endif // !RESOURCE_PACKAGE
