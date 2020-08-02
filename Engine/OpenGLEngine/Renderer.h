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
public:

	Cube cube;

	Material* material;

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

	virtual Matrix4x4 GetModelMatrix();

	virtual Vector3* GetVertices();

	virtual int GetVertexCount();

	virtual int* GetIndex();

	virtual Vector2* GetUV();

	RenderObject* GetRenderObject();

private:

	virtual void GenerateRenderObject();

	virtual void UpdateRenderObject();

	virtual void DeleteRenderObject();
};


#endif // !RENDER



