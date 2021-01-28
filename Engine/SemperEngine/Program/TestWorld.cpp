#include "TestWorld.h"
#include "BeautifulWorld.h"
#include "TestWorldAction.h"
#include "TestComponent.h"
#include "Resource.h"
#include "ResourceInternal.h"
#include "ChangeColor.h"
#include "ChangeTexture.h"

namespace SemperEngine
{
	using namespace std;

	TestWorld::TestWorld() :WorldBuilder("test", 1)
	{
	}

	void TestWorld::Build()
	{
		AddAction(new TestWorldAction());

		Camera* camera = new Camera();
		camera->transform.position = Float3(0, 1, 5);
		camera->clearColor = Color::ColorFloat(0.1f, 0.1f, 0.1f);
		AddGameObject(camera);

		auto A = new GameObject();
		A->name = "A";
		auto testCom = new TestComponent();
		A->AddComponent(testCom);
		AddGameObject(A);

		auto floor = new Cube();
		floor->name = "floor";
		floor->transform.position = Float3(0, -0.1f, 0);
		floor->transform.scale = Float3(50, 0.2f, 50);
		floor->material.reset(new Material("Texture"));
		auto tex = Resource::LoadTexture("Textures/test.png");
		floor->material->AddProperty(0, tex);
		floor->material->AddProperty("_color", Color::ColorFloat(1, 1, 1));
		AddGameObject(floor);

		auto wall_1 = new Cube();
		wall_1->name = "wall_1";
		wall_1->transform.position = Float3(10, 5, -10);
		wall_1->transform.scale = Float3(10, 10, 1);
		wall_1->transform.rotation = Quaternion::AngleAxis(-45, Float3::up);
		wall_1->material.reset(new Material("Texture"));
		auto tex1 = Resource::LoadTexture("Textures/bg1.png");
		wall_1->material->AddProperty(0, tex1);
		wall_1->material->AddProperty("_color", Color::ColorFloat(1, 1, 1));
		AddGameObject(wall_1);

		auto wall_2 = new Cube();
		wall_2->name = "wall_2";
		wall_2->transform.position = Float3(-10, 5, -10);
		wall_2->transform.scale = Float3(10, 10, 1);
		wall_2->transform.rotation = Quaternion::AngleAxis(45, Float3::up);
		wall_2->material.reset(new Material("Texture"));
		auto tex2 = Resource::LoadTexture("Textures/test.png");
		wall_2->material->AddProperty(0, tex2);
		wall_2->material->AddProperty("_color", Color::ColorFloat(1, 1, 1));
		AddGameObject(wall_2);

		auto cube1 = new Cube();
		cube1->name = "cube1";
		cube1->transform.position = Float3(0, 0.5f, 0);
		cube1->transform.rotation = (Quaternion::AngleAxis(45, Float3(0, 1, 0)) * Quaternion::AngleAxis(45, Float3(0, 0, 1)));
		cube1->material.reset(new Material("Texture"));
		cube1->material->AddProperty("_color", Color::ColorFloat(1, 1, 1));
		tex = shared_ptr<Texture>(Core::ResourceInternal::WhiteTex()->Copy());
		cube1->material->AddProperty(0, tex);
		auto changeTexture = new ChangeTexture();
		changeTexture->texture = tex;
		cube1->AddComponent(changeTexture);
		AddGameObject(cube1);

		auto cube2 = new Cube();
		cube2->name = "cube2";
		cube2->transform.position = Float3(1.0f, 0.5f, -1.5f);
		cube2->material->AddProperty("_color", Color::ColorFloat(0, 1, 0));
		auto changeColor = new ChangeColor();
		changeColor->color = Color::ColorFloat(0, 0, 0);
		changeColor->material = cube2->material;
		cube2->AddComponent(changeColor);
		AddGameObject(cube2);

		auto cube3 = new Cube();
		cube3->name = "cube3";
		cube3->transform.position = Float3(-2.0f, 0.5f, 1.f);
		cube3->material->AddProperty("_color", Color::ColorFloat(0, 0, 1));
		AddGameObject(cube3);

		auto cube4 = new Cube();
		cube4->name = "cube4";
		cube4->mesh = Resource::LoadModel("Sphere.obj")->GetMesh();
		cube4->transform.position = Float3(-4.0f, 0.5f, 0.f);
		cube4->material = wall_1->material;
		AddGameObject(cube4);
	}
}