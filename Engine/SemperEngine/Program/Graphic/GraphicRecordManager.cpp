#include "GraphicRecordManager.h"
#include "GraphicCommandManager.h"
#include "../GameSetting.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		FillList<GraphicRecord*> GraphicRecordManager::_records;

		int GraphicRecordManager::CreateRecord(int msaa)
		{
			auto record = new GraphicRecord();
			record->width = GameSetting::windowWidth;
			record->height = GameSetting::windowHeight;
			record->attach = GraphicRecord::Attach::Depth;
			record->msaa = msaa;
			auto id = _records.Add(record);

			auto cmd = shared_ptr<GCMD_CreateRecord>(new GCMD_CreateRecord(record));
			GraphicCommandManager::AddResource(cmd);
			return id;
		}

		void GraphicRecordManager::StartRecord(int id)
		{
			auto record = _records[id];
			auto cmd = shared_ptr<GCMD_StartRecord>(new GCMD_StartRecord(record));
			GraphicCommandManager::AddRender(cmd);
		}

		void GraphicRecordManager::StopRecord(int id)
		{
			auto record = _records[id];
			auto cmd = shared_ptr<GCMD_StopRecord>(new GCMD_StopRecord(record));
			GraphicCommandManager::AddRender(cmd);
		}

		void GraphicRecordManager::DeleteRecord(int id)
		{
			auto record = _records[id];
			_records.Remove(id);
			auto cmd = shared_ptr<GCMD_DeleteRecord>(new GCMD_DeleteRecord(record, DeleteRecordFunc));
		}

		GraphicRecord* GraphicRecordManager::GetRecord(int id)
		{
			return _records[id];
		}

		void GraphicRecordManager::DeleteRecordFunc(GraphicRecord* record)
		{
			delete record;
		}
	}
}