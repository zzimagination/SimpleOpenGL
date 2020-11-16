#pragma once
#ifndef __CAMERAOBJECT__
#define __CAMERAOBJECT__

#include <vector>
#include "Mathz.h"
#include "LifeContainer.h"
#include "RenderLayer.h"
#include "Render.h"

namespace SemperEngine
{
	namespace Core
	{
		class CameraObject
		{
		public:

			Matrix4x4 viewMatrix;

			Matrix4x4 projectMatrix;

			Color clearColor;

			RenderEnum::ClearMode clearMode;

			LifeContainer<CameraObject> myLife;

			RenderLayer renderLayer;

		public:

			CameraObject();

			~CameraObject();
		};
	}
}

#endif // !__CAMERAOBJECT__
