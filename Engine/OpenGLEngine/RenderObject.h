#pragma once
#include "shader.h"
#include "MeshObject.h"
#include <glm/glm.hpp>
#include "Texture.h"

using namespace std;
using namespace glm;

class RenderObject
{
private:

	struct GLTexture {
		string path;

		unsigned int ID;
	};

public:

	unsigned int VAO, VBO, EBO;

	int dataSize;

	bool isInitialized;

	bool isDeleted;

	std::vector<float> points;
	
	vector<vec3> vertices;

	std::vector<unsigned int> indices;

	vector<vec2> uvs;

	std::vector<Texture*> textures;

	Shader* shader;

	RenderObject();

	~RenderObject();

	void(*func_shader)(Shader* shader);

	void SetupGeometry();

	void ClearGeometry();

private:

	std::vector<GLTexture> glTextures;

	void SetupVertexArray();

	void SetupTextures();

	unsigned int SetupBaseTexture(int width, int height, int nrComponents, unsigned char* data);

	unsigned int SetupNormalTexture(int width, int height, unsigned char* data);
};

