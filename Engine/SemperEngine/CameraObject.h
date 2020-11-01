#pragma once
#ifndef __CAMERAOBJECT__
#define __CAMERAOBJECT__

#include <vector>
#include "Mathz.h"
#include "LifeContainer.h"
#include "RenderLayer.h"

namespace SemperEngine
{
	namespace Core
	{
		constexpr unsigned int ClearModeColor = 0x01;

		constexpr unsigned int ClearModeDepth = 0x02;

		typedef int CameraClearMode;

		class CameraObject
		{
		public:

			Matrix4x4 viewMatrix;

			Matrix4x4 projectMatrix;

			CameraClearMode clearMode;

			Color clearColor;

			LifeContainer<CameraObject> myLife;

			RenderLayer renderLayer;

		public:

			CameraObject();

			~CameraObject();
		};
	}
}

#endif // !__CAMERAOBJECT__
