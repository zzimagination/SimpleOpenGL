#include "RenderRecordManager.h"
#include "../Graphic/GraphicRecordManager.h"
#include "../Debug.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

#pragma region RenderRecordManager

		map<CameraObject*, map<string, RenderRecord>> RenderRecordManager::_recordMap;

		RenderRecord* RenderRecordManager::_current = nullptr;

		void RenderRecordManager::CreateRecord(std::string key, CameraObject* camera)
		{
			CreateRecord(key, camera, Render::MSAA::None);
		}

		void RenderRecordManager::CreateRecord(std::string key, CameraObject* camera, Render::MSAA msaa)
		{
			if (camera == nullptr)
			{
				Debug::LogError("camera can`t be null");
				return;
			}
			RenderRecord record;
			int m = 0;
			switch (msaa)
			{
			case Render::MSAA::Four:
				m = 4;
				break;
			case Render::MSAA::Eight:
				m = 8;
				break;
			case Render::MSAA::Sixteen:
				m = 16;
				break;
			}
			record.graphicID = GraphicRecordManager::CreateRecord(m);
			_recordMap[camera][key] = record;
		}

		void RenderRecordManager::StartRecord(std::string key, CameraObject* camera)
		{
			auto c = _recordMap.find(camera);
			if (c == _recordMap.end())
			{
				Debug::LogError({ "Don`t have the record." });
				return;
			}
			auto i = (*c).second.find(key);
			if (i == (*c).second.end())
			{
				Debug::LogError({ "Don`t have the record." });
				return;
			}
			GraphicRecordManager::StartRecord(i->second.graphicID);
			_current = &(i->second);
		}

		void RenderRecordManager::StopRecord()
		{
			if (_current == nullptr)
			{
				return;
			}
			GraphicRecordManager::StopRecord(_current->graphicID);
			_current = nullptr;
		}

		RenderRecord RenderRecordManager::GetRecord(std::string key, CameraObject* camera)
		{
			auto c = _recordMap.find(camera);
			if (c == _recordMap.end())
			{
				Debug::LogError({ "Don`t have the record." });
				return RenderRecord();
			}
			auto i = (*c).second.find(key);
			if (i == (*c).second.end())
			{
				Debug::LogError({ "Don`t have the record." });
				return RenderRecord();
			}
			return (*i).second;
		}

#pragma endregion

	}
}