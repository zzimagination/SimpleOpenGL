#pragma once
#ifndef __FILLLIST__
#define __FILLLIST__

#include <vector>

namespace SemperEngine
{
	namespace Core
	{
		template<class TValue>
		struct FillPair
		{
			bool usable = false;

			TValue value;
		};

		template<class T>
		class FillList
		{
		public:

		private:

			std::vector<T> _data;

			std::vector<bool> _empty;

			std::vector<int> _unused;

		public:

			FillList();

			int Add(T value);

			void Remove(int index);

			T Pop(int index);

			int Size();

			int UseSize();

			int UnuseSize();

			int AvailableId();

			FillPair<T> operator[](const int index);
		};
		template<class T>
		inline FillList<T>::FillList()
		{
		}
		template<class T>
		inline int FillList<T>::Add(T value)
		{
			if (_unused.size() > 0)
			{
				auto last = *(_unused.end() - 1);
				_data[last] = value;
				_empty[last] = false;
				_unused.pop_back();
				return last;
			}
			else
			{
				int i = (int)_data.size();
				_data.push_back(value);
				_empty.push_back(false);
				return i;
			}
		}
		template<class T>
		inline void FillList<T>::Remove(int index)
		{
			if (index >= _data.size())
			{
				throw "out of range";
			}
			if (!_empty[index])
			{
				_empty[index] = true;
				_unused.push_back(index);
				_data[index] = T();
			}
		}
		template<class T>
		inline T FillList<T>::Pop(int index)
		{
			if (index >= _data.size())
			{
				throw "out of range";
			}
			if (!_empty[index])
			{
				_empty[index] = true;
				_unused.push_back(index);
				auto result = _data[index];
				_data[index] = T();
				return result;
			}
			return _data[index];
		}
		template<class T>
		inline int FillList<T>::Size()
		{
			return _data.size();
		}
		template<class T>
		inline int FillList<T>::UseSize()
		{
			return _data.size() - _unused.size();
		}
		template<class T>
		inline int FillList<T>::UnuseSize()
		{
			return _unused.size();
		}
		template<class T>
		inline int FillList<T>::AvailableId()
		{
			if (_unused.size() > 0)
			{
				return *(_unused.end() - 1);
			}
			else
			{
				return _data.size();
			}
		}
		template<class T>
		inline FillPair<T> FillList<T>::operator[](const int index)
		{
			if (_empty[index])
			{
				FillPair<T> result;
				result.usable = false;
				return result;
			}
			else
			{
				FillPair<T> result;
				result.usable = true;
				result.value = _data[index];
				return result;
			}
		}
	}
}

#endif // !__FILLLIST__
