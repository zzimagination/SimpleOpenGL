#include "CreateRecordSection.h"
#include "../RenderRecordManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		CreateRecordSection::CreateRecordSection(std::string name) : name(name)
		{
		}

		CreateRecordSection::~CreateRecordSection()
		{
		}
		void CreateRecordSection::Prepare()
		{
		}
		void CreateRecordSection::Start()
		{
			RenderRecordManager::CreateRecord(name, camera, MSAA , MSAASample);
		}
	}
}