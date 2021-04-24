#include "GraphicRecordManager.h"
#include "GraphicCommandManager.h"
#include "../GameSetting.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		std::vector<GraphicRecord*> GraphicRecordManager::_tempRecords;
		std::vector<GraphicRecord*> GraphicRecordManager::_inUseRecords;

		int GraphicRecordManager::CreateRecord(string name, bool msaa, int sample)
		{
			auto record = new GraphicRecord();
			record->name = name;
			record->width = GameSetting::windowWidth;
			record->height = GameSetting::windowHeight;
			record->attach = GraphicRecord::Attach::Depth;
			record->msaa = msaa;
			record->sample = sample;
			_tempRecords.push_back(record);
			auto cmd = shared_ptr<GCMD_CreateRecord>(new GCMD_CreateRecord(record));
			GraphicCommandManager::AddRender(cmd);
			return (int)_tempRecords.size() - 1;
		}

		void GraphicRecordManager::StopRecord()
		{
			auto cmd = shared_ptr<GCMD_StopRecord>(new GCMD_StopRecord);
			GraphicCommandManager::AddRender(cmd);
		}

		GraphicRecord* GraphicRecordManager::UseRecord(int id)
		{
			return _inUseRecords[id];
		}

		void GraphicRecordManager::Clear()
		{
			for (size_t i = 0; i < _inUseRecords.size(); i++)
			{
				auto cmd = shared_ptr<GCMD_ClearRecord>(new GCMD_ClearRecord);
				cmd->record = _inUseRecords[i];
				GraphicCommandManager::AddResource(cmd);
			}
		}

		void GraphicRecordManager::Swap()
		{
			for (size_t i = 0; i < _inUseRecords.size(); i++)
			{
				delete _inUseRecords[i];
			}
			_inUseRecords = _tempRecords;
			_tempRecords.clear();
		}
	}
}