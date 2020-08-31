#include "ComponentCollection.h"
#include "Component.h"

namespace SemperEngine
{
	ComponentCollection::ComponentCollection()
	{
		_current = -1;
	}
	void ComponentCollection::Add(Component * com)
	{
		if (com == nullptr)
		{
			throw "NULL";
		}
		auto index = HasCom(com);
		if (index >= 0)
		{
			throw "already have this item";
		}
		GCCItem item = { com,false };
		_coms.push_back(item);
	}

	void ComponentCollection::Remove(Component * com)
	{
		if (com == nullptr)
		{
			throw "NULL";
		}
		auto index = HasCom(com);
		if (index < 0)
		{
			throw "don't have this item";
		}
		_coms[index].isRemove = true;
	}

	int ComponentCollection::Size()
	{
		int size = 0;
		for (int i = 0; i < _coms.size(); i++)
		{
			if (!_coms[i].isRemove)
			{
				size++;
			}
		}
		return size;
	}

	void ComponentCollection::Clear()
	{
		_current = -1;
		_coms.clear();
	}

	void ComponentCollection::Reset()
	{
		_current = -1;
		for (int i = _coms.size() - 1; i >= 0; i--)
		{
			if (_coms[i].isRemove)
			{
				_coms.erase(_coms.begin() + i);
			}
		}
	}

	void ComponentCollection::AddRange(ComponentCollection range)
	{
		range.Reset();
		while (true)
		{
			auto com = range.Next();
			if (com == nullptr)
			{
				return;
			}
			if (HasCom(com) >= 0)
			{
				continue;
			}
			GCCItem item = { com, false };
			_coms.push_back(item);
		}
	}

	Component * ComponentCollection::Next()
	{
		_current++;
		if (_current >= _coms.size())
		{
			return nullptr;
		}
		while (_coms[_current].isRemove)
		{
			_current++;
			if (_current >= _coms.size())
			{
				return nullptr;
			}
		}
		return _coms[_current].com;
	}


	bool ComponentCollection::Contain(Component * com)
	{
		return HasCom(com) >= 0;
	}

	int ComponentCollection::HasCom(Component * com)
	{
		for (int i = 0; i < _coms.size(); i++)
		{
			if (_coms[i].isRemove)
			{
				continue;
			}
			if (_coms[i].com == com)
			{
				return i;
			}
		}
		return -1;
	}
}