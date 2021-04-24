#include "StopRecordSection.h"
#include "../RenderRecordManager.h"

namespace SemperEngine
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