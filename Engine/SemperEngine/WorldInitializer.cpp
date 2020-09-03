#include "WorldInitializer.h"
#include "WorldStorageCenter.h"
#include "WorldInternal.h"
#include "SemperEngine.h"
#include "TestComponent.h"

namespace SemperEngine
{
	namespace Core
	{
		WorldInternal* WorldInitializer::CreateWorld_1()
		{
			WorldInternal* world = new WorldInternal("Main");

			Camera* main = new Camera();
			main->position = Vector3(0, 2, 10);
			main->projection = Projection::Perspective;
			world->camera = main;

			Player* player = new Player("xiao ming");
			world->AddGameObject(player);
			player->times = 1;
			auto renderer = player->AddComponent<Renderer>();
			renderer->SetMaterial(new Material("UnlitTexture"));
			renderer->GetMaterial()->SetVector3(Vector3(1, 1, 1), "_color");
			Texture* tex = new Texture();
			tex->LoadFile("Resources/Textures/test.png");
			renderer->GetMaterial()->SetTexture(tex);
			player->AddComponent<TestComponent>();

			Player* target = new Player("xiao hong");
			world->AddGameObject(target);
			target->times = 2;
			target->transform->position = Vector3(-4, 4, 0);
			auto renderer1 = target->AddComponent<Renderer>();
			renderer1->SetMaterial(new Material("Debug"));
			renderer1->GetMaterial()->SetVector3(Vector3(1, 0, 0), "Color");

			Player* viewer = new Player("zhang san");
			world->AddGameObject(viewer);
			viewer->times = 0.5f;
			viewer->transform->position = Vector3(4, 4, 0);
			auto renderer2 = viewer->AddComponent<Renderer>();
			renderer2->SetMaterial(new Material("Debug"));
			renderer2->GetMaterial()->SetVector3(Vector3(0, 0, 1), "Color");

			return world;
		}

		WorldInternal* WorldInitializer::CreateWorld_2()
		{
			return nullptr;
		}

		WorldInternal* WorldInitializer::CreateWorld_3()
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