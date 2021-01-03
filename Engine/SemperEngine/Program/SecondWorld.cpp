#include "SecondWorld.h"
#include "SecondWorldAction.h"
#include "TestComponent.h"
#include "Camera.h"
#include "Cube.h"

namespace SemperEngine
{
	SecondWorld::SecondWorld() : WorldBuilder("second", 2)
	{
	}

	void SecondWorld::Build()
	{
		AddAction(new SecondWorldAction());

		Camera* camera = new Camera();
		camera->transform.position = Float3(0, 2, 2.4f);
		camera->clearColor = Color::ColorFloat(0.0f, 0.0f, 0.0f);
		AddGameObject(camera);

		auto floor = new Cube();
		floor->name = "floor";
		floor->transform.position = Float3(0, -0.1f, 0);
		floor->transform.scale = Float3(50, 0.2f, 50);
		floor->material->AddProperty("_color", Color::ColorFloat(0.9f, 0.6f, 0.0f));
		AddGameObject(floor);

		auto cube = new Cube();
		cube->name = "cube";
		cube->transform.position = Float3(0, 0.5f, 0);
		cube->material->AddProperty("_color", Color::ColorFloat(0, 0.4f, 1));
		AddGameObject(cube);
	}
}