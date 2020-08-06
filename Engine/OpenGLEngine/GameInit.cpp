#include "WorldManager.h"
#include "ShaderManager.h"
#include "Texture.h"
#include "Components.h"
#include "GameInit.h"
#include "Player.h"
#include "Mathz.h"

void GameInit::Init()
{
	World* world = WorldManager::CreateWorld("main");

	Camera* main = new Camera();
	main->position = Vector3(0, 2, 10);
	world->camera = main;

	Player* player = new Player("xiao ming");
	world->AddGameObject(player);
	player->times = 1;
	auto renderer = player->GetComponent<Renderer*>();
	renderer->SetMaterial(new Material("UnlitTexture"));
	renderer->GetMaterial()->SetVector3(Vector3(1, 1, 1), "_color");
	Texture* tex = new Texture();
	tex->LoadFile("Resources/Textures/test.png");
	renderer->GetMaterial()->SetTexture(tex);

	Player* target = new Player("xiao hong");
	world->AddGameObject(target);
	target->times = 2;
	target->transform.position = Vector3(-4, 4, 0);
	auto renderer1 = target->GetComponent<Renderer*>();
	renderer1->SetMaterial(new Material("Debug"));
	renderer1->GetMaterial()->SetVector3(Vector3(1, 0, 0), "Color");

	Player* viewer = new Player("zhang san");
	world->AddGameObject(viewer);
	viewer->times = 0.5f;
	viewer->transform.position = Vector3(4, 4, 0);
	auto renderer2 = viewer->GetComponent<Renderer*>();
	renderer2->SetMaterial(new Material("Debug"));
	renderer2->GetMaterial()->SetVector3(Vector3(0, 0, 1), "Color");
}