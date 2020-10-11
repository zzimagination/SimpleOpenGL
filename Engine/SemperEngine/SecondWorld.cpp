#include "SecondWorld.h"
#include "SecondWorldAction.h"
#include "ComponentCreator.h"
#include "TestComponent.h"

namespace SemperEngine
{
	SecondWorld::SecondWorld() : WorldBuilder("second", 2)
	{
	}
	World SecondWorld::Build()
	{
		auto world = World(name, id);
		AddAction(new SecondWorldAction());

		Camera* camera = new Camera();
		camera->transform.position = Vector3(0, 2, 2.4f);
		camera->clearColor = Color(0.0f, 0.0f, 0.0f);
		AddGameObject(camera);

		auto floor = new Cube();
		floor->name = "floor";
		floor->transform.position = Vector3(0, -0.1f, 0);
		floor->transform.scale = Vector3(50, 0.2f, 50);
		floor->material->AddShaderProperty("_color", Color(0.9f, 0.6f, 0.0f));
		AddGameObject(floor);

		auto cube = new Cube();
		cube->name = "cube";
		cube->transform.position = Vector3(0, 0.5f, 0);
		cube->material->AddShaderProperty("_color", Color(0, 0.4f, 1));
		AddGameObject(cube);
		return world;
	}
}