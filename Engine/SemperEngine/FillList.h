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
		public:

		private:

			std::vector<T> _data;

			std::vector<bool> _empty;

			std::vector<int> _unused;

		public:

			FillList()
			{

			}

			int Add(T value)
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

			void Remove(int index)
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

			T Pop(int index)
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

			int Size()
			{
				return _data.size();
			}

			int UseSize()
			{
				return _data.size() - _unused.size();
			}

			int UnuseSize()
			{
				return _unused.size();
			}

			int AvailableId()
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

			T& operator[](const int index)
			{
				return _data[index];
			}
		};
	}
}

#endif // !__FILLLIST__
