#pragma once
#ifndef __RENDERSCREENOBJECT__
#define __RENDERSCREENOBJECT__

#include <memory>
#include "RenderObject.h"
#include "Material.h"

namespace SemperEngine
{
	namespace Core
	{
		class RenderScreenObject : public RenderObject
		{
		public:

			std::shared_ptr<Material> material;

		public:

			RenderScreenObject();

			virtual ~RenderScreenObject() override;

		};
	}
}

#endif // !__RENDERSCREENOBJECT__
