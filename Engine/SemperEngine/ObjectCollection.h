#pragma once
#ifndef OBJECTCOLLECTION
#define OBJECTCOLLECTION
#include <vector>

namespace SemperEngine
{
	namespace Collection
	{
		template<class T>
		class ObjectCollection
		{
		private:

			struct Item
			{
				T* object;

				bool isRemoved;

				bool operator == (const Item & value) const
				{
					bool result = this->object == value.object;
					result = result && (this->isRemoved == value.isRemoved);
					return result;
				}
			};

		private:

			std::vector<Item> _objects;

			int _current;

		public:

			ObjectCollection();

			void Add(T* object);
			
			void Remove(T* object);

			T *Next();

			void Reset();

			int Size();

			void Clear();

			bool Contain(T *object);

		private:

			int ItemIndex(T* item);


			void RealRemove();
		};

	}
}

#include "ObjectCollection.hpp"

#endif // !OBJECTCOLLECTION
