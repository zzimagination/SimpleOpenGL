#include "RenderRecordManager.h"
#include "../Graphic/GraphicRecordManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		std::vector<RenderRecord> RenderRecordManager::_records;

		void RenderRecordManager::CreateRecord(string name, CameraObject* camera)
		{
			auto id = GraphicRecordManager::CreateRecord(name);
			RenderRecord record;
			record.graphicID = id;
			record.name = name;
			record.camera = camera;
			_records.push_back(record);
		}

		void RenderRecordManager::StopRecord()
		{
			GraphicRecordManager::StopRecord();
		}
		std::vector<int> RenderRecordManager::GetGraphicRecords(std::vector<RenderRecord> records)
		{
			vector<int> result;
			for (size_t i = 0; i < records.size(); i++)
			{
				for (size_t j = 0; j < _records.size(); j++)
				{
					if (_records[j] == records[i])
					{
						result.push_back(_records[j].graphicID);
						break;
					}
				}
			}
			return result;
		}


		RenderRecord::RenderRecord()
		{
		}

		RenderRecord::RenderRecord(CameraObject* camera, std::string name) : camera(camera), name(name)
		{
		}

		bool RenderRecord::operator==(const RenderRecord& record)
		{
			return this->name == record.name && this->camera == record.camera;
		}
	}
}