#ifndef __RESOURCEMESHLIBRARY__
#define __RESOURCEMESHLIBRARY__

#include "ResourceLibrary.h"
#include "MeshObject.h"

namespace SemperEngine
{
	namespace Core
	{
		class ResourceMeshLibrary : public ResourceLibrary<MeshObject>
		{
		private:

			MeshObject* _screen = nullptr;

		public:

			virtual ~ResourceMeshLibrary() override;

			MeshObject* ScreenObject();
		};
	}
}

#endif // !__RESOURCEMESHLIBRARY__
