#include "GraphicRecordManager.h"
#include "GraphicCommand.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		vector<std::shared_ptr<GraphicRecord>> GraphicRecordManager::_recordListA;
		vector<std::shared_ptr<GraphicRecord>> GraphicRecordManager::_recordListB;

		bool GraphicRecordManager::_isRenderA = true;

		GraphicRecord* GraphicRecordManager::CreateRecord(std::string name)
		{
			auto record = std::shared_ptr<GraphicRecord>(new GraphicRecord(name));
			record->managerID = (int)_recordListA.size();
			_recordListA.push_back(record);
			auto result = record.get();
			return result;
		}
		GraphicRecord* GraphicRecordManager::GetRecord(int id)
		{
			return _recordListB[id].get();
		}

		GraphicRecord* GraphicRecordManager::GetRecord(std::string name)
		{
			for (auto i = _recordListB.begin(); i != _recordListB.end(); i++)
			{
				if (i->get()->name == name)
				{
					return i->get();
				}
			}
			return nullptr;
		}

		vector<GraphicRecord*> GraphicRecordManager::GetExecuteList()
		{
			vector<GraphicRecord*> result;
			for (auto i = _recordListB.begin(); i != _recordListB.end(); i++)
			{
				result.push_back(i->get());
			}
			return result;
		}

		void GraphicRecordManager::Clear()
		{
		}

		void GraphicRecordManager::Swap()
		{
			for (size_t i = 0; i < _recordListB.size(); i++)
			{
				GCMD_ClearRecord cmd;
				cmd.record = _recordListB[i].get();
				cmd.Excute();
			}
			_recordListB.clear();
			_recordListB = _recordListA;
			_recordListA.clear();
		}
	}
}