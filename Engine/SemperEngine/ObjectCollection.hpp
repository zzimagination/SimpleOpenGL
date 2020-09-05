#include "ObjectCollection.h"

namespace SemperEngine
{
	namespace Collection
	{
		template<class T>
		inline ObjectCollection<T>::ObjectCollection()
		{
			_current = -1;
		}
		template<class T>
		inline void ObjectCollection<T>::Add(T* object)
		{
			if (object == nullptr)
			{
				throw "NULL";
			}

			auto index = ItemIndex(object);
			if (index >= 0)
			{
				throw "already have this object";
			}
			Item item = { object, false };
			_objects.push_back(item);
		}

		template<class T>
		inline void ObjectCollection<T>::Remove(T* object)
		{
			if (object == nullptr)
			{
				throw "NULL";
			}

			auto index = ItemIndex(object);
			if (index < 0)
			{
				throw "don't have this object";
			}
			_objects[index].isRemoved = true;
		}

		template<class T>
		inline T *ObjectCollection<T>::Next()
		{
			_current++;
			for (int i = _current; i < _objects.size(); i++)
			{
				if (!_objects[i].isRemoved)
				{
					return _objects[i].object;
				}
				_current++;
			}
			return nullptr;
		}

		template<class T>
		inline void ObjectCollection<T>::Reset()
		{
			_current = -1;
			RealRemove();
		}

		template<class T>
		inline int ObjectCollection<T>::Size()
		{
			int size = 0;
			for (int i = 0; i < _objects.size(); i++)
			{
				if (_objects[i].isRemoved)
				{
					size++;
				}
			}
			return size;
		}

		template<class T>
		inline void ObjectCollection<T>::Clear()
		{
			_current = -1;
			_objects.clear();
		}

		template<class T>
		inline bool ObjectCollection<T>::Contain(T* object)
		{
			return ItemIndex(object) >= 0;
		}

		template<class T>
		inline int ObjectCollection<T>::ItemIndex(T *object)
		{
			for (int i = 0; i < _objects.size(); i++)
			{
				if (_objects[i].object == object)
				{
					return i;
				}
			}
			return -1;
		}

		template<class T>
		inline void ObjectCollection<T>::RealRemove()
		{
			for (int i = _objects.size() - 1; i >= 0; i--)
			{
				if (_objects[i].isRemoved)
				{
					_objects.pop_back();
				}
			}
		}
	}
}