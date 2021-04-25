#include "GraphicRecord.h"

namespace Semper
{
	namespace Core
	{
		bool GraphicRecord::MSAAEnable()
		{
			return this->msaa > 0;
		}
	}
}