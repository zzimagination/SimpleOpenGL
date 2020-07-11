#include "WorldManager.h"
#include "ShaderManager.h"
#include "Texture.h"
#include "Components.h"
#include "GameInit.h"
#include "Player.h"
#include "Mathz.hpp"

void GameInit::Init()
{
	World* world = WorldManager::CreateWorld("main");

	Camera* main = new Camera();
	main->Position = glm::vec3(0.0f, 2.0f, 6.0f);
	main->eulerAngle = glm::vec3(-15, 0, 0);
	main->projection = Camera::Projection::Perspective;
	main->size = 2.5f;
	main->CalculateVectors();
	world->camera = main;

	Texture* tex = new Texture();
	tex->textureType = BASE_TEXTURE;
	tex->LoadTexture("Resources/Textures/test.png");

	Player* player = new Player("xiao ming");
	player->transform.position = glm::vec3(0, 0, 0);
	player->transform.eulerAngle = glm::vec3(0, 0, 0);

	Renderer* renderer = new Renderer();
	renderer->modelMatrix = player->transform.GetModelMatrix();
	renderer->vec3Map["_color"] = glm::vec3(1, 1, 1);
	renderer->AddTexture(tex);
	renderer->shader = ShaderManager::GetShader("UnlitTexture");
	player->AddComponent(renderer);

	world->AddGameObject(player);
}
