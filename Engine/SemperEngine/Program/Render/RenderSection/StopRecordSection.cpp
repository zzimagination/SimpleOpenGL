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
		}
		void StopRecordSection::Start()
		{
			RenderRecordManager::StopRecord();
		}
	}
}