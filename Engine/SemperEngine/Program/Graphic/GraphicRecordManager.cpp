#include "GraphicRecordManager.h"
#include "../GraphicCommand.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		vector<std::shared_ptr<GraphicRecord>> GraphicRecordManager::_recordListA;
		vector<std::shared_ptr<GraphicRecord>> GraphicRecordManager::_recordListB;

		GraphicRecord* GraphicRecordManager::lastRecord = nullptr;

		GraphicRecord* GraphicRecordManager::currentRecord = nullptr;

		bool GraphicRecordManager::_isRenderA = true;

		GraphicRecord* GraphicRecordManager::CreateRecord(std::string name)
		{
			auto record = std::shared_ptr<GraphicRecord>(new GraphicRecord(name));
			if (_isRenderA)
			{
				record->managerID = (int)_recordListB.size();
				_recordListB.push_back(record);
			}
			else
			{
				record->managerID = (int)_recordListA.size();
				_recordListA.push_back(record);
			}
			auto result = record.get();
			return result;
		}
		GraphicRecord* GraphicRecordManager::GetRecord(int id)
		{
			if (_isRenderA)
			{
				return _recordListA[id].get();
			}
			else
			{
				return _recordListB[id].get();
			}
		}

		GraphicRecord* GraphicRecordManager::GetRecord(std::string name)
		{
			if (_isRenderA)
			{
				for (auto i = _recordListB.begin(); i != _recordListB.end(); i++)
				{
					if (i->get()->name == name)
					{
						return i->get();
					}
				}
			}
			else
			{
				for (auto i = _recordListA.begin(); i != _recordListA.end(); i++)
				{
					if (i->get()->name == name)
					{
						return i->get();
					}
				}
			}
			return nullptr;
		}

		vector<GraphicRecord*> GraphicRecordManager::GetExecuteList()
		{
			vector<GraphicRecord*> result;
			if (_isRenderA)
			{
				for (auto i = _recordListA.begin(); i != _recordListA.end(); i++)
				{
					result.push_back(i->get());
				}
			}
			else
			{
				for (auto i = _recordListB.begin(); i != _recordListB.end(); i++)
				{
					result.push_back(i->get());
				}
			}
			return result;
		}

		void GraphicRecordManager::Clear()
		{

			if (_isRenderA)
			{
				for (size_t i = 0; i < _recordListA.size(); i++)
				{
					GCMD_ClearRecord cmd;
					cmd.record = _recordListA[i].get();
					cmd.Excute();
				}
				_recordListA.clear();
			}
			else
			{
				for (size_t i = 0; i < _recordListB.size(); i++)
				{
					GCMD_ClearRecord cmd;
					cmd.record = _recordListB[i].get();
					cmd.Excute();
				}
				_recordListB.clear();
			}
		}

		void GraphicRecordManager::Swap()
		{
			_isRenderA = !_isRenderA;
		}
	}
}