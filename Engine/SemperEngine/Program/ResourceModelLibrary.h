#ifndef __RESOURCEMESHLIBRARY__
#define __RESOURCEMESHLIBRARY__

#include "ResourceLibrary.h"
#include "ModelObject.h"
#include "NativeResource.h"

namespace Semper
{
	namespace Core
	{
		class ResourceModelLibrary : public ResourceLibrary<ModelObject>
		{
		public:

			virtual ~ResourceModelLibrary() override;

			ModelObject* Load(std::string path);

		private:

			void AddMesh(ModelLib::Node& native, ModelObject::Node& game, std::string path);

			void AddNode(ModelLib::Node& native, ModelObject::Node& game, std::string path);
		};
	}
}

#endif // !__RESOURCEMESHLIBRARY__
