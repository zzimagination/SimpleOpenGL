#ifndef __RENDEROBJECT__
#define __RENDEROBJECT__

#include <memory>
#include "Common.h"
#include "RenderLayer.h"
#include "Mesh.h"
#include "Material.h"

namespace SemperEngine {

	namespace Core
	{
		class RenderObject
		{
		public:

			LifeContainer<RenderObject> mylife;

			RenderLayer layer;

		public:

			RenderObject();

			virtual ~RenderObject();
		};
	}
}

#include "CameraObject.h"
#include "RenderCustomObject.h"
#include "RenderScreenObject.h"


#endif // !RRENDEROBJECT
