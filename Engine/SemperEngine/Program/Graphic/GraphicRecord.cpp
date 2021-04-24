#include "GraphicRecord.h"

namespace SemperEngine
{
	namespace Core
	{
		bool GraphicRecord::MSAAEnable()
		{
			return this->msaa > 0;
		}
	}
}