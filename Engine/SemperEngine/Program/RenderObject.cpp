#include "RenderObject.h"
#include "RenderCollection.h"

namespace Semper {

	namespace Core
	{
		RenderObject::RenderObject()
		{
			mylife = LifeContainer<RenderObject>(this);
		}

		RenderObject::~RenderObject()
		{
			*mylife.life = false;
		}

	}
}