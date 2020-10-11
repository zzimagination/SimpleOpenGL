#pragma once
#ifndef __OBJECTCOLLECTION__
#define __OBJECTCOLLECTION__
#include <vector>

namespace SemperEngine
{
	namespace Collection
	{
		template<class T>
		class ObjectCollection
		{
		private:

			struct Packing
			{
				T* object;

				bool isRemoved;

				bool operator == (const Packing & value) const
				{
					bool result = this->object == value.object;
					result = result && (this->isRemoved == value.isRemoved);
					return result;
				}
			};

		private:

			std::vector<Packing> _objects;

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

			void Dispose();

		private:

			int ItemIndex(T* item);

			void RealRemove();
		};

	}
}

#include "ObjectCollection.hpp"

#endif // !OBJECTCOLLECTION
