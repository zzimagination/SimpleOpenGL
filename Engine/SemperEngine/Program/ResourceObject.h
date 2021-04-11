#ifndef __RESOURCEOBJECT__
#define __RESOURCEOBJECT__

#include <string>
#include <memory>
#include "Common.h"

namespace SemperEngine
{
	namespace Core
	{
		class ResourceObjectCenter;

		class ResourceObject
		{
		public:

			int id = 0;

			std::string name = "";

			std::string filePath = "";

			int useCount = 0;

		private:

			bool used = false;

		public:

			ResourceObject();

			virtual ~ResourceObject();

			int Use();

			int Dispose();

			void Modify();

		protected:

			virtual void OnUse();

			virtual void OnDispose();

			virtual void Delete();

			virtual void EndCreate();

			virtual void EndDelete();

			virtual void EndModify();

		public:

			friend class ResourceObjectCenter;
		};

		class IResourceTarget
		{
		public:
			virtual ResourceObject* GetObject() = 0;
		};
	}
}

#endif // !__RESOURCEOBJECT__
