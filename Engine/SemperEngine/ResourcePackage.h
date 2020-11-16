#pragma once
#ifndef __RESOURCE_PACKAGE__
#define __RESOURCE_PACKAGE__

#include<memory>
#include "DataCenterClerk.h"

namespace SemperEngine
{
	namespace Core
	{
		template<class T>
		class ResourcePackage
		{
		public:

			std::shared_ptr<DataCenterClerk> clerk;

		private:

			T* _data;

			std::shared_ptr<bool> _isEmpty;

			std::shared_ptr<int> _useCount;

		public:

			ResourcePackage()
			{
				EmptyPackage();
			}

			ResourcePackage(T* resource)
			{
				if (resource == nullptr)
				{
					EmptyPackage();
					return;
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
					return nullptr;
				}
				return _data;
			}

			void Use()
			{
				if (IsEmpty())
				{
					throw "empty";
				}
				*_useCount = *_useCount + 1;
			}

			void Dispose()
			{
				if (IsEmpty())
				{
					return;
				}
				*_useCount = *_useCount - 1;
				if (*_useCount <= 0)
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

			void EmptyPackage()
			{
				_useCount = std::shared_ptr<int>(new int(0));
				_isEmpty = std::shared_ptr<bool>(new bool(true));
			}

			void Destory()
			{
				delete _data;
				*_isEmpty = true;
				if (clerk.get() != nullptr)
				{
					clerk->Destory();
				}
			}
		};
	}
}

#endif // !RESOURCE_PACKAGE
