#include "TestWorld.h"
#include "Debug.h"
#include "TestWorldAction.h"
#include "Camera.h"
#include "Cube.h"
#include "ComponentCreator.h"
#include "TestComponent.h"
#include "Resource.h"

namespace SemperEngine
{
	using namespace std;

	TestWorld::TestWorld() :WorldBuilder("test", 1)
	{
	}


	World TestWorld::Build()
	{
		auto world = World(name, id);
		AddAction(new TestWorldAction());

		Camera* camera = new Camera();
		camera->transform.position = Vector3(0, 1, 5);
		camera->clearColor = Color(0.1f, 0.1f, 0.1f);
		AddGameObject(camera);

		auto A = new GameObject();
		A->name = "A";
		ComponentCreator::Create(new TestComponent(), A);
		AddGameObject(A);

		auto floor = new Cube();
		floor->name = "floor";
		floor->transform.position = Vector3(0, -0.1f, 0);
		floor->transform.scale = Vector3(50, 0.2f, 50);
		floor->material.reset(new Material("Texture"));
		auto tex = Resource::LoadTexture("Resources/Textures/test.png");
		floor->material->AddProperty(0, tex);
		floor->material->AddProperty("_color", Color(1, 1, 1));
		AddGameObject(floor);


		auto cube1 = new Cube();
		cube1->name = "cube1";
		cube1->transform.position = Vector3(0, 0.5f, 0);
		cube1->transform.rotation = (Quaternion::AngleAxis(45, Vector3(0, 1, 0)) * Quaternion::AngleAxis(45, Vector3(0, 0, 1)));
		cube1->material->AddProperty("_color", Color(1, 0, 0));
		AddGameObject(cube1);

		auto cube2 = new Cube();
		cube2->name = "cube2";
		cube2->transform.position = Vector3(1.0f, 0.5f, -1.5f);
		cube2->material->AddProperty("_color", Color(0, 1, 0));
		AddGameObject(cube2);

		auto cube3 = new Cube();
		cube3->name = "cube3";
		cube3->transform.position = Vector3(-2.0f, 0.5f, 1.f);
		cube3->material->AddProperty("_color", Color(0, 0, 1));
		AddGameObject(cube3);

		return world;
	}


}