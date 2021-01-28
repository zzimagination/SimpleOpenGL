#pragma once
#ifndef __ARRAYLIST__
#define __ARRAYLIST__

#include <memory>

namespace SemperEngine
{
	template<class T>
	class ArrayList
	{
	private:

		struct deleter
		{
			void operator()(T* ptr)
			{
				delete[] ptr;
			}
		};

	private:

		std::shared_ptr<T> _data;

		std::size_t _size = 0;

	public:

		ArrayList() {};

		ArrayList(std::size_t s)
		{
			_size = s;
			_data = std::shared_ptr<T>(new T[s], deleter());
		}

		ArrayList(T* data, std::size_t s)
		{
			_size = s;
			_data = std::shared_ptr<T>(data, deleter());
		}

		std::shared_ptr<T> Data()
		{
			return _data;
		}

		T* DataPtr()
		{
			return _data.get();
		}

		size_t Size()
		{
			return _size;
		}

		void Resize(std::size_t s)
		{
			_data.reset();
			_size = s;
			_data = std::shared_ptr<T>(new T[s]);
		}

		void Copy(T* source)
		{
			memcpy(_data.get(), source, _size * sizeof(T));
		}

		T& operator[](int i)
		{
			return *(_data.get() + i);
		}
	};
}

#endif // !__ARRAYLIST__
