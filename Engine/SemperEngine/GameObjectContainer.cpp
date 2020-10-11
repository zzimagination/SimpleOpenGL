#include "GameObjectContainer.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		void GameObjectContainer::AddComponent(LifeContainer<Component> com)
		{
			EncodeComID(com.self, _components.size() + _newComponents.size());
			_newComponents.push_back(com);
		}

		void GameObjectContainer::StartComponents()
		{
			auto temp = _newComponents;
			_newComponents.clear();
			for (int i = 0; i < temp.size(); i++)
			{
				auto com = temp[i];
				if (!*com.life)
				{
					continue;
				}
				com.self->Start();
				_components.push_back(com);
			}
		}

		void GameObjectContainer::UpdateComponents()
		{
			for (int i = 0; i < _components.size(); i++)
			{
				auto com = _components[i];
				if (!*com.life)
				{
					continue;
				}
				com.self->Update();
			}
			vector<LifeContainer<Component>> next;
			for (int i = 0; i < _components.size(); i++)
			{
				auto com = _components[i];
				if (!*com.life)
				{
					continue;
				}
				EncodeComID(com.self, (unsigned int)next.size());
				next.push_back(com);
			}
			_components = next;
		}

		void GameObjectContainer::EndComponents()
		{
			for (int i = 0; i < _components.size(); i++)
			{
				auto com = _components[i];
				com.self->End();
				delete com.self;
			}
		}
		unsigned int GameObjectContainer::DecodeComID(Component* com)
		{
			auto id = com->comID.ID() - 1;
			return id;
		}
		void GameObjectContainer::EncodeComID(Component* com, unsigned int i)
		{
			com->comID = i + 1;
		}
	}
}