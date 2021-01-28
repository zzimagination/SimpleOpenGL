#ifndef __RESOURCEMESHLIBRARY__
#define __RESOURCEMESHLIBRARY__

#include "ResourceLibrary.h"
#include "ModelObject.h"

namespace SemperEngine
{
	namespace Core
	{
		class ResourceModelLibrary : public ResourceLibrary<ModelObject>
		{
		public:

			virtual ~ResourceModelLibrary() override;

			ModelObject* Load(std::string path);

		};
	}
}

#endif // !__RESOURCEMESHLIBRARY__
