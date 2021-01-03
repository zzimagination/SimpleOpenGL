#ifndef __RESOURCEOBJECT__
#define __RESOURCEOBJECT__

#include <string>
#include <memory>

namespace SemperEngine
{
	namespace Core
	{

		class ResourceObject
		{
		public:

			int id = 0;

			std::string filePath = "";

			int useCount = 0;

		public:

			ResourceObject();

			virtual ~ResourceObject();

			int Use();

			int Dispose();

			void Modify();

			virtual void EndCreate();

			virtual void EndDelete();

			virtual void EndModify();
		};
	}
}

#endif // !__RESOURCEOBJECT__
