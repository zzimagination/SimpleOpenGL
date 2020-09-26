#include "RenderObject.h"
#include "RenderCollection.h"

namespace SemperEngine {

	namespace Core
	{
		RenderObject::RenderObject()
		{
		}

		RenderObject::~RenderObject()
		{
			*mylife.life = false;
		}

	}
}