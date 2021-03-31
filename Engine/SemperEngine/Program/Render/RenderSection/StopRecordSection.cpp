#include "StopRecordSection.h"
#include "../RenderRecordManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		StopRecordSection::~StopRecordSection()
		{
		}
		void StopRecordSection::Prepare()
		{
			RenderRecordManager::StopRecord();
		}
		void StopRecordSection::Start()
		{
		}
	}
}