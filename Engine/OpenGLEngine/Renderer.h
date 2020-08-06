#ifndef RENDERER
#define RENDERER
#include <vector>
#include <map>
#include "ShaderProgram.h"
#include "BuildInMesh.h"
#include "Component.h"
#include "Texture.h"
#include "Material.h"

class RenderObject;

using namespace std;

class Renderer : public Component
{
private:

	Cube cube;

	Material* _material;

public:

	Renderer();

	~ Renderer();

	virtual void Start() override;

	virtual void Update() override;

private:

	RenderObject* _renderObject;

public:

	void Collect();

	void Drop();

	virtual Material* GetMaterial();

	virtual void SetMaterial(Material *material);

	RenderObject* GetRenderObject();

private:

	virtual void GenerateRenderObject();

	virtual void UpdateRenderObject();

	virtual void DeleteRenderObject();
};


#endif // !RENDER