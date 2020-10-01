#pragma once
#ifndef RESOURCE_PACKAGE
#define RESOURCE_PACKAGE

#include<memory>

namespace SemperEngine
{
	namespace Core
	{

		class VertexDataCenter;

		template<class T>
		class ResourcePackage
		{
		public:

			std::shared_ptr<int> graphicCenterID;

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
				graphicCenterID = std::shared_ptr<int>(new int(0));
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
				if (_user == user)
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
				*_useCount = *_useCount - 1;
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
