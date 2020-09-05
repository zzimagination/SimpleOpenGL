#pragma once
#ifndef GAMEOBJECT_COLLECTION
#define GAMEOBJECT_COLLECTION
#include <vector>
namespace SemperEngine
{
	class GameObject;

	class GameObjectCollection
	{
	private:

		struct WGObjectItem
		{
			GameObject* object;

			bool isRemove;

		};

	private:

		std::vector<WGObjectItem> _objects;

		int _current;

	public:

		GameObjectCollection();

		void Add(GameObject* object);

		void AddRange(GameObjectCollection range);

		void Remove(GameObject* object);

		int Size();

		void Clear();

		bool Contain(GameObject* object);

		GameObject* Next();

		void Reset();

	private:

		int HasObject(GameObject* object);

		void RemoveExtra();
	};
}

#endif // !GAMEOBJECT_COLLECTION
