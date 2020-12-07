#ifndef __RESOURCEOBJECT__
#define __RESOURCEOBJECT__

#include <string>

namespace SemperEngine
{
	namespace Core
	{
		class ResourceObject
		{
		public:

			int id = 0;

			std::string filePath;

			int useCount = 0;

		protected:

			bool shared = false;

			bool readOnly = false;

		public:

			ResourceObject() {}

			ResourceObject(bool isShared) : shared(isShared)
			{}

			virtual ~ResourceObject() {}

			int Use()
			{
				useCount++;
				return useCount;
			}

			int Dispose()
			{
				useCount--;
				return useCount;
			}

			bool IsShared()
			{
				return shared;
			}

			bool ReadOnly()
			{
				return readOnly;
			}
		};
	}
}

#endif // !__RESOURCEOBJECT__
