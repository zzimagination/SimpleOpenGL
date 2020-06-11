#include "../World/WorldManager.h"
#include "../Render/ShaderManager.h"
#include "../2D/Texture.h"
#include "../Component/Components.h"
#include "GameInit.h"
#include "Player.h"

void GameInit::Init()
{
	World* world = WorldManager::CreateWorld("main");

	Camera* main = new Camera();
	main->Position = glm::vec3(0.0f, 2.0f, 6.0f);
	main->eulerAngle = vec3(-15, 0, 0);
	main->projection = Camera::Projection::Perspective;
	main->size = 2.5f;
	main->CalculateVectors();
	world->camera = main;

	Texture* tex = new Texture();
	tex->textureType = BASE_TEXTURE;
	tex->LoadTexture("Resources/Textures/test.png");

	Player* player = new Player("xiao ming");
	player->transform.position = vec3(0, 0, 0);
	player->transform.eulerAngle = vec3(0, 0, 0);

	Renderer* renderer = new Renderer();
	renderer->modelMatrix = player->transform.GetModelMatrix();
	renderer->vec3Map["_color"] = vec3(1, 1, 1);
	renderer->AddTexture(tex);
	renderer->shader = ShaderManager::GetShader("UnlitTexture");
	player->AddComponent(renderer);

	world->AddGameObject(player);
}
