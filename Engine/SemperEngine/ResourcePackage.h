#pragma once
#ifndef __RESOURCE_PACKAGE__
#define __RESOURCE_PACKAGE__

#include<memory>
#include "ObjectIndex.h"

namespace SemperEngine
{
	namespace Core
	{
		class VertexDataCenter;

		template<class T>
		class ResourcePackage
		{
		public:

			ObjectIndex graphicResourceID;

		private:

			void* _user;

			T* _data;

			std::shared_ptr<bool> _isEmpty;

			std::shared_ptr<int> _useCount;

			bool _isDestroy;

		public:

			ResourcePackage()
			{
				_isEmpty = std::shared_ptr<bool>(new bool(true));
				_isDestroy = true;
			}

			ResourcePackage(T* resource)
			{
				if (resource == nullptr)
				{
					throw "NULL";
				}
				_data = resource;
				_useCount = std::shared_ptr<int>(new int(0));
				_isEmpty = std::shared_ptr<bool>(new bool(false));
				_isDestroy = false;
			}

			~ResourcePackage()
			{
			}

			T* GetResource()
			{
				if (_isDestroy)
				{
					return nullptr;
				}
				if (*_isEmpty)
				{
					return nullptr;
				}
				return _data;
			}

			void Use(void* user)
			{
				if (_isDestroy)
				{
					throw "disposed";
				}
				if (_user == user || user == nullptr)
				{
					return;
				}
				_user = user;
				*_useCount = *_useCount + 1;
			}

			void Dispose()
			{
				if (_isDestroy)
				{
					return;
				}
				_isDestroy = true;
				_data = nullptr;

				if (_user == nullptr)
				{
					return;
				}
				_user = nullptr;
				*_useCount = *_useCount - 1;
				if (*_useCount < 0)
				{
					throw "count can't less 0";
				}
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
				_isDestroy = true;
			}


		public:

			friend class VertexDataCenter;
		};
	}
}

#endif // !RESOURCE_PACKAGE
