#include "GameObjectCollection.h"

namespace SemperEngine
{
	GameObjectCollection::GameObjectCollection()
	{
		_current = -1;
	}

	void GameObjectCollection::Add(GameObject * object)
	{
		auto index = HasObject(object);
		if (index >= 0)
		{
			throw "had this object";
		}
		WGObjectItem item = { object, false };
		_objects.push_back(item);
	}

	void GameObjectCollection::AddRange(GameObjectCollection range)
	{
		range.Reset();
		while (true)
		{
			auto gameObject = range.Next();
			if (gameObject == nullptr)
			{
				return;
			}
			if (HasObject(gameObject) >= 0)
			{
				continue;
			}
			WGObjectItem item = { gameObject, false };
			_objects.push_back(item);
		}
	}

	void GameObjectCollection::Remove(GameObject * object)
	{
		auto index = HasObject(object);
		if (index < 0)
		{
			throw "don't have this object";
		}
		_objects[index].isRemove = true;
	}

	int GameObjectCollection::Size()
	{
		int size = 0;
		for (int i = 0; i < _objects.size(); i++)
		{
			if (!_objects[i].isRemove)
			{
				size++;
			}
		}
		return size;
	}

	void GameObjectCollection::Clear()
	{
		_current = -1;
		_objects.clear();
	}

	bool GameObjectCollection::Contain(GameObject * object)
	{
		return HasObject(object) >= 0;
	}

	GameObject * GameObjectCollection::Next()
	{
		_current++;
		if (_current >= _objects.size())
		{
			RemoveExtra();
			return nullptr;
		}
		while (_objects[_current].isRemove)
		{
			_current++;
			if (_current >= _objects.size())
			{
				RemoveExtra();
				return nullptr;
			}
		}
		auto result = _objects[_current];
		return result.object;
	}

	void GameObjectCollection::Reset()
	{
		_current = -1;
		RemoveExtra();
	}

	int GameObjectCollection::HasObject(GameObject * object)
	{
		for (int i = 0; i < _objects.size(); i++)
		{
			if (_objects[i].isRemove)
			{
				continue;
			}
			if (_objects[i].object == object)
			{
				return i;
			}
		}
		return -1;
	}

	void GameObjectCollection::RemoveExtra()
	{
		for (int i = _objects.size() - 1; i >= 0; i--)
		{
			if (_objects[i].isRemove)
			{
				_objects.erase(_objects.begin() + i);
			}
		}
	}
}