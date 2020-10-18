#pragma once
#ifndef __RESOURCE_REFERENCE__
#define __RESOURCE_REFERENCE__

#include "ResourcePackage.h"

namespace SemperEngine
{
	namespace Core
	{
		template<class T>
		class ResourceReference
		{
		private:

			ResourcePackage<T> _package;

		public:
		
			ResourceReference(ResourcePackage<T> package)
			{
				_package = package;
				_package.Use(this);
			}

			~ResourceReference()
			{
				_package.Dispose(this);
			}

			T GetResource()
			{
				return _package.GetResource();
			}

			ResourcePackage<T> GetPackage()
			{
				return _package;
			}
		};
	}
}


#endif // !__RESOURCE_INSTANCE__
