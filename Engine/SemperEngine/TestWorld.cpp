#include "TestWorld.h"
#include "Debug.h"
#include "TestWorldAction.h"
#include "Camera.h"
#include "Cube.h"
#include "ComponentCreator.h"
#include "TestComponent.h"

namespace SemperEngine
{
	using namespace std;

	//TestWorld::TestWorld(std::string name, int id) : WorldBuilder(name, id)
	//{
	//	/*Camera* main = new Camera();
	//	main->position = Vector3(0, 2, 10);
	//	main->projection = Projection::Perspective;
	//	camera = main;

	//	auto floor = CreateGameObject<Cube>();
	//	floor->renderer->SetMainColor(Vector4(0.3, 0.3, 0.3, 1));
	//	floor->GetTransform()->position = Vector3(0, -1.5, 0);
	//	floor->GetTransform()->scale = Vector3(50, 0.5, 50);

	//	auto player = CreateGameObject<Cube>("xiao ming");
	//	player->renderer->SetMainColor(Vector4(0.9, 0.9, 0.9, 1));
	//	player->AddComponent<TestComponent>();


	//	auto left = CreateGameObject<Cube>();
	//	left->GetTransform()->position = Vector3(-4, 0, 0);
	//	left->renderer->SetMainColor(Vector4(1, 0, 0, 1));

	//	auto right = CreateGameObject<Cube>();
	//	right->GetTransform()->position = Vector3(4, 0, 0);
	//	right->renderer->SetMainColor(Vector4(0, 0, 1, 1));*/
	//}

	TestWorld::TestWorld() :WorldBuilder("test", 1)
	{
	}


	World TestWorld::Build()
	{
		//Cube* cube1 = new Cube();
		//cube1->transform.position = Vector3(-4, -4, 0);
		//gameObjects.push_back(cube1);

		//Cube* cube2 = new Cube();
		//cube2->transform.position = Vector3(-4, 4, 0);
		//gameObjects.push_back(cube2);

		//Cube* cube3 = new Cube();
		//cube3->transform.position = Vector3(4, 4, 0);
		//gameObjects.push_back(cube3);

		//Camera* camera = new Camera();
		//camera->transform.position = Vector3(0, 0, 10);
		//gameObjects.push_back(camera);


		auto world = World(name, id);
		AddAction(new TestWorldAction());
		auto A = new GameObject("A");
		ComponentCreator::Create(new TestComponent(), A);
		AddGameObject(A);
		return world;
	}


}