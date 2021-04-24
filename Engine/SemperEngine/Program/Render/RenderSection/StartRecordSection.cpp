#include "StartRecordSection.h"
#include "../RenderRecordManager.h"

namespace SemperEngine
{
	namespace Core
	{
		StartRecordSection::StartRecordSection(std::string key)
		{
			this->key = key;
		}
		StartRecordSection::~StartRecordSection()
		{
		}

		void StartRecordSection::Start()
		{
			if (!_created)
			{
				_created = true;
				RenderRecordManager::CreateRecord(key, camera, msaa);
			}
			RenderRecordManager::StartRecord(key, camera);
		}
	}
}
