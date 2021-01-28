#ifndef __RESOURCEMATERIALLIBRARY__
#define __RESOURCEMATERIALLIBRARY__

#include <string>
#include <map>
#include "ResourceLibrary.h"
#include "Material.h"

namespace SemperEngine
{
	namespace Core
	{
		class ResourceMaterialLibrary : public ResourceLibrary<MaterialObject>
		{
		public:

			virtual ~ResourceMaterialLibrary() override;

		};
	}
}

#endif // !__RESOURCEMATERIALLIBRARY__
