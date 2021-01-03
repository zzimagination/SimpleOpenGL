#include "WorldContainer.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		WorldContainer::WorldContainer()
		{
		}
		WorldContainer::~WorldContainer()
		{
		}
		void WorldContainer::Add(GameObject* gameObject)
		{
			auto cabin = new GameCabin();
			cabin->objectLife = gameObject->life;
			cabin->gameObject = gameObject;
			newCabins.push_back(cabin);
		}

		void WorldContainer::Start()
		{
			//for (size_t i = 0; i < newCabins.size(); i++)
			//{
			//	auto cabin = newCabins[i];
			//	if (cabin->Dead())
			//	{
			//		continue;
			//	}
			//	cabin->gameObject->Start();
			//}
			int i = 0;
			int size = (int)newCabins.size();
			if (i < size) 
			{
				do
				{
					auto cabin = newCabins[i];
					if (cabin->Dead())
					{
						i++;
						continue;
					}
					cabin->gameObject->Start();
					i++;
				} while (i < size);
			}

			i = 0;
			size = (int)newCabins.size();
			vector<GameCabin*> nc;
			nc.reserve(newCabins.size());
			if (i < size) 
			{
				do
				{
					auto cabin = newCabins[i];
					if (cabin->Dead())
					{
						delete cabin;
						i++;
						continue;
					}
					cabins.push_back(newCabins[i]);
					i++;
				} while (i < size);
			}
			//for (size_t i = 0; i < newCabins.size(); i++)
			//{
			//	auto cabin = newCabins[i];
			//	if (cabin->Dead())
			//	{
			//		delete cabin;
			//		continue;
			//	}
			//	cabins.push_back(newCabins[i]);
			//}
			newCabins = nc;

			i = 0;
			size = (int)cabins.size();
			if (i < size)
			{
				do
				{
					auto cabin = cabins[i];
					if (cabin->Dead())
					{
						i++;
						continue;
					}
					cabin->gameObject->container.Start();
					i++;
				} while (i < size);
			}
			//for (size_t i = 0; i < cabins.size(); i++)
			//{
			//	auto cabin = cabins[i];
			//	if (cabin->Dead())
			//	{
			//		continue;
			//	}
			//	cabin->gameObject->container.Start();
			//}
		}

		void WorldContainer::Update()
		{
			//for (int i = 0; i < cabins.size(); i++)
			//{
			//	auto cabin = cabins[i];
			//	if (cabin->Dead())
			//	{
			//		continue;
			//	}
			//	cabin->gameObject->Update();
			//}
			int i = 0;
			int size = (int)cabins.size();
			if (i < size) {
				do
				{
					auto cabin = cabins[i];
					if (cabin->Dead())
					{
						i++;
						continue;
					}
					cabin->gameObject->Update();
					i++;
				} while (i < size);
			}

			i = 0;
			if (i < size) {
				do
				{
					auto cabin = cabins[i];
					if (cabin->Dead())
					{
						i++;
						continue;
					}
					cabin->gameObject->container.Update();
					i++;
				} while (i < size);
			}
			//for (size_t i = 0; i < cabins.size(); i++)
			//{
			//	auto cabin = cabins[i];
			//	if (cabin->Dead())
			//	{
			//		continue;
			//	}
			//	cabin->gameObject->container.Update();
			//}

			i = 0;
			vector<GameCabin*> leftCabins;
			leftCabins.reserve(cabins.size());
			if (i < size) {
				do
				{
					auto cabin = cabins[i];
					if (cabin->Dead())
					{
						delete cabin;
						i++;
						continue;
					}
					leftCabins.push_back(cabin);
					i++;
				} while (i < size);
			}
			//for (size_t i = 0; i < cabins.size(); i++)
			//{
			//	auto cabin = cabins[i];
			//	if (cabin->Dead())
			//	{
			//		delete cabin;
			//		continue;
			//	}
			//	leftCabins.push_back(cabin);
			//}
			cabins = leftCabins;
		}

		void WorldContainer::End()
		{
			for (size_t i = 0; i < newCabins.size(); i++)
			{
				if (!newCabins[i]->Dead())
				{
					delete newCabins[i]->gameObject;
				}
				delete newCabins[i];
			}
			newCabins.clear();
			for (int i = 0; i < cabins.size(); i++)
			{
				auto cabin = cabins[i];
				if (!cabin->Dead())
				{
					delete cabin->gameObject;
				}
				delete cabin;
			}
			cabins.clear();
		}
	}
}