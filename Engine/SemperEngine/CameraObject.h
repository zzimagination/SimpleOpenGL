#pragma once
#ifndef __CAMERAOBJECT__
#define __CAMERAOBJECT__

#include <vector>
#include "Mathz.h"
#include "LifeContainer.h"

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

			std::vector<int> renderLayer;

			LifeContainer<CameraObject> myLife;

		public:

			CameraObject();

			~CameraObject();
		};
	}
}

#endif // !__CAMERAOBJECT__
