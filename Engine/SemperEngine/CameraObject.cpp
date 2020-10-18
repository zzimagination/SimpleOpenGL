#include "CameraObject.h"

namespace SemperEngine
{
	namespace Core
	{
		CameraObject::CameraObject()
		{
			myLife = LifeContainer<CameraObject>(this);
		}
		CameraObject::~CameraObject()
		{
			*myLife.life = false;
		}
	}
}