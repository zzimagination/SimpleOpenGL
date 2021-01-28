#ifndef __RESOURCEOBJECT__
#define __RESOURCEOBJECT__

#include <string>
#include <memory>
#include "Collection.h"

namespace SemperEngine
{
	namespace Core
	{
		class ResourceObjectCenter;

		class ResourceObject
		{
		public:

			int id = 0;

			std::string filePath = "";

			int useCount = 0;

		private:

			bool used = false;

		public:

			ResourceObject();

			virtual ~ResourceObject();

			int Use();

			int Dispose();

		protected:

			void Modify();

			virtual void OnUse();

			virtual void OnDispose();

			virtual void Delete();

			virtual void EndCreate();

			virtual void EndDelete();

			virtual void EndModify();

		public:

			friend class ResourceObjectCenter;
		};
	}
}

#endif // !__RESOURCEOBJECT__
