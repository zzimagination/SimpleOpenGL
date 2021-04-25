#ifndef __RENDERCUSTOMOBJECT__
#define __RENDERCUSTOMOBJECT__

#include <memory>
#include "Mesh.h"
#include "Material.h"
#include "RenderObject.h"

namespace Semper
{
	namespace Core
	{
		class RenderCustomObject : public RenderObject
		{
		public:

			std::shared_ptr<Mesh> mesh;

			Matrix4x4 modelMat;

			std::shared_ptr<Material> material;

		public:

			RenderCustomObject();

			virtual ~RenderCustomObject() override;
		};
	}
}

#endif // !__RENDERCUSTOMOBJECT__
