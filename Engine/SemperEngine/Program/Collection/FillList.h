#pragma once
#ifndef __FILLLIST__
#define __FILLLIST__

#include <vector>

namespace SemperEngine
{
	namespace Core
	{
		template<class T>
		class FillList
		{
		private:

			struct Item
			{
				T value;

				bool empty = true;
			};

		private:

			std::vector<T> _data;

			std::vector<bool> _empty;

			std::vector<Item> _items;

			std::vector<int> _unused;

		public:

			FillList();

			int Add(T value);

			void Remove(int index);

			bool IsEmpty(int index);

			size_t Size();

			size_t UnuseSize();

			T operator[](const int& index);
		};
		template<class T>
		FillList<T>::FillList()
		{
		}
		template<class T>
		int FillList<T>::Add(T value)
		{
			if (_unused.size() > 0)
			{
				auto last = *(_unused.end() - 1);
				_unused.pop_back();
				_items[last].value = value;
				_items[last].empty = false;
				return last;
			}

			int id = (int)_items.size();
			Item item;
			item.value = value;
			item.empty = false;
			_items.push_back(item);
			return id;
		}
		template<class T>
		void FillList<T>::Remove(int index)
		{
			if (_items[index].empty)
			{
				throw "value is empty";
				return;
			}

			_items[index].empty = true;
			_items[index].value = T();
			_unused.push_back(index);
		}
		template<class T>
		inline bool FillList<T>::IsEmpty(int index)
		{
			return _items[index].empty;
		}

		template<class T>
		inline size_t FillList<T>::Size()
		{
			return _items.size();
		}

		template<class T>
		inline size_t FillList<T>::UnuseSize()
		{
			return _unused.size();
		}

		template<class T>
		T FillList<T>::operator[](const int& index)
		{
			return _items[index].value;
		}
	}
}

#endif // !__FILLLIST__
