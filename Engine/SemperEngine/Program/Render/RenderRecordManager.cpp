#include "RenderRecordManager.h"
#include "../Graphic/GraphicRecordManager.h"
#include "../Debug.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		std::vector<RenderRecord> RenderRecordManager::_records;

		void RenderRecordManager::CreateRecord(string name, CameraObject* camera, bool msaa, Render::MSAA sample)
		{
			int sampleNumber = 4;
			switch (sample)
			{
			case Render::MSAA::m4:
				sampleNumber = 4;
				break;
			case Render::MSAA::m8:
				sampleNumber = 8;
				break;
			case Render::MSAA::m16:
				sampleNumber = 16;
				break;
			}
			auto id = GraphicRecordManager::CreateRecord(name, msaa, sampleNumber);
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

		int RenderRecordManager::GetGraphicRecord(RenderRecord record)
		{
			auto id = FindRecord(record);
			return _records[id].graphicID;
		}

		std::vector<int> RenderRecordManager::GetGraphicRecords(std::vector<RenderRecord> records)
		{
			vector<int> result;
			for (size_t i = 0; i < records.size(); i++)
			{
				auto id = FindRecord(records[i]);
				result.push_back(_records[id].graphicID);
			}
			return result;
		}

		int RenderRecordManager::FindRecord(RenderRecord record)
		{
			for (size_t j = 0; j < _records.size(); j++)
			{
				if (_records[j] == record)
				{
					return (int)j;
				}
			}
			Debug::LogError({ "don't have the record", record.name });
			abort();
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