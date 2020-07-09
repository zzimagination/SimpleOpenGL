#pragma once
#include <map>
#include "shader.h"
#include "MeshObject.h"
#include "Mathz.h"
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

	size_t dataSize;

	mat4 modelMatrix;

	mat4 viewMatrix;

	mat4 projectionMatrix;

	std::vector<float> points;
	
	vector<vec3> vertices;

	std::vector<unsigned int> indices;

	vector<vec2> uvs;

	vector<Texture*> textures;

	map<string, vec3> vec3Map;

	Shader* shader;

	RenderObject();

	~RenderObject();

	void(*func_shader)(Shader* shader);

	void SetupGeometry();

	void ClearGeometry();

	void AddVec3Value(string name, vec3 color);

private:

	bool isSetup;

	vector<GLTexture> glTextures;

	void SetupVertexArray();


	void SetupTextures();

	unsigned int SetupBaseTexture(int width, int height, int nrComponents, unsigned char* data);

	unsigned int SetupNormalTexture(int width, int height, unsigned char* data);
};

