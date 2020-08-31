#pragma once
#ifndef COMPONENT_COLLECTION
#define COMPONENT_COLLECTION
#include <vector>

namespace SemperEngine
{
	class Component;

	struct GCCItem
	{
		Component* com;

		bool isRemove;
	};

	class ComponentCollection
	{
	private:

		std::vector<GCCItem> _coms;

		int _current;

	public:

		ComponentCollection();

		void Add(Component* com);

		void Remove(Component* com);

		int Size();

		void Clear();

		void Reset();

		void AddRange(ComponentCollection range);

		Component* Next();

		bool Contain(Component* com);

	private:

		int HasCom(Component* com);
	};
}

#endif // !COMPONENT_COLLECTION
