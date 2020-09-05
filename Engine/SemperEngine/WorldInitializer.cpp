#include "WorldInitializer.h"
#include "WorldStorageCenter.h"
#include "WorldInternal.h"
#include "SemperEngine.h"
#include "TestComponent.h"
#include <typeinfo>

namespace SemperEngine
{
	namespace Core
	{
		WorldInstance* WorldInitializer::CreateWorld_1()
		{
			WorldInstance* world = new WorldInstance("Main");

			Camera* main = new Camera();
			main->position = Vector3(0, 2, 10);
			main->projection = Projection::Perspective;
			world->camera = main;

			Player* player = new Player("xiao ming");
			world->AddGameObject(player);
			player->times = 1;

			auto test = new TestComponent();
			player->AddComponent(test);

			Player* target = new Player();
			world->AddGameObject(target);
			target->times = 2;
			target->GetTransform()->position = Vector3(-4, 4, 0);
			auto renderer1 = (Renderer*)target->GetComponent(typeid(Renderer));
			renderer1->GetMaterial()->SetVector3(Vector3(1, 0, 0), "_color");

			Player* viewer = new Player();
			world->AddGameObject(viewer);
			viewer->times = 0.5f;
			viewer->GetTransform()->position = Vector3(4, 4, 0);
			auto r =(Renderer*) viewer->GetComponent(typeid(Renderer));
			r->GetMaterial()->SetVector3(Vector3(1, 0.7, 0), "_color");
			return world;
		}

		WorldInstance* WorldInitializer::CreateWorld_2()
		{
			return nullptr;
		}

		WorldInstance* WorldInitializer::CreateWorld_3()
		{
			return nullptr;
		}

		void WorldInitializer::Initialize()
		{
			auto world1 = CreateWorld_1();
			WorldStorageCenter::Add(world1);
		}
	}
}