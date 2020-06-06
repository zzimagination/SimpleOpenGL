#pragma once
#include <vector>
#include "../Render/shader.h"
#include "../Object/BuildInMesh.h"
#include "Component.h"
#include "../2D/Texture.h"

using namespace std;

class Renderer :
	public Component
{
public:

	Cube cube;

	mat4 modelMatrix;

	Shader *shader;

	vector<Texture*> textures;

	void(*func_shader)(Shader* shader);

	virtual Renderer* GetType();

	virtual void Start();

	virtual void Update();

	void AddTexture(Texture* tex);

	void RemoveTexture(Texture* tex);
};

