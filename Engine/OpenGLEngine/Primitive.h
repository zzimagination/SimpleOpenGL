#ifndef PRIMITIVE_H
#define PRIMITIVE_H

using namespace glm;

class Primitive
{
public:
	enum ObjType
	{
		cube,
		plane
	};

	vec3 position;
	vec3 eularAngle;
	vec3 scale;
	glm::mat4 modelMat4;
	Primitive(ObjType c);
	~Primitive();
	void Draw(Shader shader);
	void SetTransform(glm::vec3 position=vec3(0), glm::vec3 eularAngle=vec3(0), glm::vec3 scale=vec3(1));
private:
	struct Vertex
	{
		vec3 position;
		vec2 texcoord;
		vec3 normal;
		vec3 tangent;
		vec3 bitangent;
		Vertex(float x, float y, float z, float u, float v)
		{
			position = vec3(x, y, z);
			texcoord = vec2(u, v);
		}
	};
	std::vector<Vertex> dataBuffer;

	unsigned int VBO, VAO, EBO;
	ObjType type;

	void CreatObjData(ObjType type);
	void CalculateTangent(Vertex v[]);
};

#endif