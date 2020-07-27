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
	main->position = Vector3(0, 1, -10);
	main->aspect = 16.0f / 9.0f;
	main->size = 5;
	main->fov = 65;
	main->nearPlane = 1;
	main->farPlane = 100;
	main->projection = Projection::Orthographic;

	Matrix4x4 view = main->CalculateViewMatrix();
	cout << view.x0 << " " << view.y0 << " " << view.z0 << " " << view.w0 << endl;
	cout << view.x1 << " " << view.y1 << " " << view.z1 << " " << view.w1 << endl;
	cout << view.x2 << " " << view.y2 << " " << view.z2 << " " << view.w2 << endl;
	cout << view.x3 << " " << view.y3 << " " << view.z3 << " " << view.w3 << endl;
	view = main->CalculateProjectionMatrix();
	cout << view.x0 << " " << view.y0 << " " << view.z0 << " " << view.w0 << endl;
	cout << view.x1 << " " << view.y1 << " " << view.z1 << " " << view.w1 << endl;
	cout << view.x2 << " " << view.y2 << " " << view.z2 << " " << view.w2 << endl;
	cout << view.x3 << " " << view.y3 << " " << view.z3 << " " << view.w3 << endl;
	//main->Position = glm::vec3(0.0f, 2.0f, 6.0f);
	//main->eulerAngle = glm::vec3(-15, 0, 0);
	//main->projection = Camera::Projection::Perspective;
	//main->size = 2.5f;
	//main->CalculateVectors();
	//world->camera = main;

	//Texture* tex = new Texture();
	//tex->textureType = BASE_TEXTURE;
	//tex->LoadTexture("Resources/Textures/test.png");

	//Player* player = new Player("xiao ming");
	//player->transform.position = glm::vec3(0, 0, 0);
	//player->transform.eulerAngle = glm::vec3(0, 0, 0);

	//Renderer* renderer = new Renderer();
	//renderer->modelMatrix = player->transform.GetModelMatrix();
	//renderer->vec3Map["_color"] = glm::vec3(1, 1, 1);
	//renderer->AddTexture(tex);
	//renderer->shader = ShaderManager::GetShader("UnlitTexture");
	//player->AddComponent(renderer);

	//world->AddGameObject(player);
}
