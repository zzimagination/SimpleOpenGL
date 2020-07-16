#pragma once
#include <vector>
#include <map>
#include "ShaderProgram.h"
#include "BuildInMesh.h"
#include "Component.h"
#include "Texture.h"

using namespace std;


class Renderer :
	public Component
{
public:

	Cube cube;

	Matrix4x4 modelMatrix;

	ShaderProgram *shader;

	map<string, vec3> vec3Map;

	vector<Texture*> textures;

	virtual Renderer* GetType();

	virtual void Start();

	virtual void Update();

	void SetModelMatrix(Matrix4x4 model);

	void AddTexture(Texture* tex);

	void RemoveTexture(Texture* tex);
};

