#ifndef __CAMERAOBJECT__
#define __CAMERAOBJECT__

#include <vector>
#include "Common.h"
#include "RenderObject.h"

namespace SemperEngine
{
	namespace Core
	{
		class CameraObject : public RenderObject
		{
		public:

			float near;

			float far;

			Matrix4x4 viewMatrix;

			Matrix4x4 projectMatrix;

			Color clearColor;

			Graphic::ClearMode clearMode;

		public:

			CameraObject();

			virtual ~CameraObject() override;
		};
	}
}

#endif // !__CAMERAOBJECT__
