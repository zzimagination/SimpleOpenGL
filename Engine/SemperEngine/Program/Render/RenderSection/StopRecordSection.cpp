#include "StopRecordSection.h"
#include "../RenderRecordManager.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

		void StopRecordSection::Start()
		{
			RenderRecordManager::StopRecord();
		}
	}
}