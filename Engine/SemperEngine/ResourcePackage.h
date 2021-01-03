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

		public:

			ResourcePackage();

			ResourcePackage(T* resource);

			~ResourcePackage();

			T* GetResource();

			void Dispose();

			bool IsEmpty();

		private:

			void EmptyPackage();

			void Destroy();
		};
		template<class T>
		inline ResourcePackage<T>::ResourcePackage()
		{
			EmptyPackage();
		}
		template<class T>
		ResourcePackage<T>::ResourcePackage(T* resource)
		{
			if (resource == nullptr)
			{
				EmptyPackage();
				return;
			}
			_data = resource;
			_isEmpty = std::shared_ptr<bool>(new bool(false));
		}
		template<class T>
		inline ResourcePackage<T>::~ResourcePackage()
		{
		}
		template<class T>
		T* ResourcePackage<T>::GetResource()
		{
			if (IsEmpty())
			{
				return nullptr;
			}
			return _data;
		}

		template<class T>
		void ResourcePackage<T>::Dispose()
		{
			if (IsEmpty())
			{
				return;
			}
			Destroy();
		}

		template<class T>
		inline bool ResourcePackage<T>::IsEmpty()
		{
			return *_isEmpty;
		}
		template<class T>
		inline void ResourcePackage<T>::EmptyPackage()
		{
			_isEmpty = std::shared_ptr<bool>(new bool(true));
		}
		template<class T>
		void ResourcePackage<T>::Destroy()
		{
			delete _data;
			*_isEmpty = true;
			if (clerk != nullptr)
			{
				clerk->Destroy();
			}
		}
	}
}

#endif // !RESOURCE_PACKAGE
