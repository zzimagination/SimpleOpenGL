#pragma once
#include <vector>
#include <map>
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

	map<string, vec3> vec3Map;

	vector<Texture*> textures;

	virtual Renderer* GetType();

	virtual void Start();

	virtual void Update();

	void SetModelMatrix(mat4 model);

	void AddTexture(Texture* tex);

	void RemoveTexture(Texture* tex);
};

