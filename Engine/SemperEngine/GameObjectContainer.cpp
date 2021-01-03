#include "GameObjectContainer.h"
#include "Debug.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		void GameObjectContainer::AddComponent(Component* com)
		{
			auto slot = new GameSlot();
			slot->component = com;
			slot->componentLife = com->life;
			_newSlots.push_back(slot);
			_slots.push_back(slot);
		}

		void GameObjectContainer::Remove(std::type_index type)
		{
			delete GetComponent(type);
		}

		void GameObjectContainer::Start()
		{
			//for (int i = 0; i < _newSlots.size(); i++)
			//{
			//	auto com = _newSlots[i];
			//	if (com->Dead())
			//	{
			//		continue;
			//	}
			//	com->component->Start();
			//}
			int i = 0;
			int size = (int)_newSlots.size();
			if (i < size) {
				do
				{
					auto com = _newSlots[i];
					if (com->Dead())
					{
						i++;
						continue;
					}
					com->component->Start();
					i++;
				} while (i < size);
			}

			i = 0;
			size = (int)_newSlots.size();
			vector<GameSlot*> ns;
			ns.reserve(_newSlots.size());
			if (i < size) {
				do
				{
					auto slot = _newSlots[i];
					if (slot->Dead())
					{
						delete slot;
						i++;
						continue;
					}
					i++;
				} while (i < size);
			}
			//for (size_t i = 0; i < _newSlots.size(); i++)
			//{
			//	auto slot = _newSlots[i];
			//	if (slot->Dead())
			//	{
			//		delete slot;
			//		continue;
			//	}
			//}
			_newSlots = ns;
		}

		void GameObjectContainer::Update()
		{
			//for (int i = 0; i < _slots.size(); i++)
			//{
			//	auto com = _slots[i];
			//	if (com->Dead())
			//	{
			//		continue;
			//	}
			//	com->component->Update();
			//}
			int i = 0;
			int size = (int)_slots.size();
			if (i < size) {
				do
				{
					auto com = _slots[i];
					if (com->Dead())
					{
						i++;
						continue;
					}
					com->component->Update();
					i++;
				} while (i < size);
			}

			i = 0;
			size = (int)_slots.size();
			vector<GameSlot*> ns;
			ns.reserve(_slots.size());
			if (i < size) {
				do
				{
					auto slot = _slots[i];
					if (slot->Dead())
					{
						delete slot;
						i++;
						continue;
					}
					ns.push_back(slot);
					i++;
				} while (i < size);
			}
			//for (size_t i = 0; i < _slots.size(); i++)
			//{
			//	auto slot = _slots[i];
			//	if (slot->Dead())
			//	{
			//		delete slot;
			//		continue;
			//	}
			//	ns.push_back(slot);
			//}
			_slots = ns;
		}

		void GameObjectContainer::End()
		{
			for (size_t i = 0; i < _newSlots.size(); i++)
			{
				if (!_newSlots[i]->Dead())
				{
					delete _newSlots[i]->component;
				}
				delete _newSlots[i];
			}
			_newSlots.clear();
			for (int i = 0; i < _slots.size(); i++)
			{
				if (!_slots[i]->Dead())
				{
					delete _slots[i]->component;
				}
				delete _slots[i];
			}
			_slots.clear();
		}

		std::vector<Component*> GameObjectContainer::GetComponents()
		{
			vector<Component*> result;
			result.reserve(_slots.size());
			for (size_t i = 0; i < _slots.size(); i++)
			{
				if (_slots[i]->Dead())
				{
					i++;
					continue;
				}
				result.push_back(_slots[i]->component);
			}
			return result;
		}

		Component* GameObjectContainer::GetComponent(type_index type)
		{
			for (size_t i = 0; i < _slots.size(); i++)
			{
				if (type == typeid(_slots[i]))
				{
					return _slots[i]->component;
				}
			}
			Debug::LogError({ "can't find component ", type.name() });
			return nullptr;
		}
	}
}