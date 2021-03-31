#include "CreateRecordSection.h"
#include "../RenderRecordManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		CreateRecordSection::~CreateRecordSection()
		{
		}
		void CreateRecordSection::Prepare()
		{
			RenderRecordManager::CreateRecord("Unlit");
		}
		void CreateRecordSection::Start()
		{
		}
	}
}