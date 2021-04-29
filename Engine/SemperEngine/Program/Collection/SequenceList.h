#ifndef __SEQUENCE__
#define __SEQUENCE__

#include <list>
#include "Collection.h"

namespace Semper
{
	template<class T>
	class SequenceList
	{
	private:

		std::list<Pair<T, int>> _container;

	public:

		void Add(T value)
		{
			_container.push_back(Pair<T, int>(value, -1));
		}

		void Add(T value, int order)
		{
			if (order < 0)
			{
				throw "Weight don`t less 0.";
				return;
			}
			for (auto i = _container.begin(); i != _container.end(); i++)
			{
				if (i->value > order || i->value < 0)
				{
					_container.insert(i, Pair<T, int>(value, order));
					return;
				}
			}
			_container.push_back(Pair<T, int>(value, order));
		}

		void Remove(T value)
		{
			for (auto i = _container.begin(); i != _container.end(); i++)
			{
				if (i->key == value)
				{
					_container.erase(i);
					break;
				}
			}
			throw "Don`t have the value";
		}

		int Count()
		{
			return _container.size();
		}

		std::vector<T> ToVector()
		{
			std::vector<T> result;
			for (auto i = _container.begin(); i != _container.end(); i++)
			{
				result.push_back(i->key);
			}
			return result;
		}
	};
}

#endif
