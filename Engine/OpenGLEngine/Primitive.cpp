#include <vector>
#include <string>

#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Render/shader.h"
#include "Primitive.h"

using namespace glm;

Primitive::Primitive(ObjType c)
{
	type = c;
	CreatObjData(c);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*dataBuffer.size(), &dataBuffer[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texcoord));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(3,3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, tangent));
	glEnableVertexAttribArray(3);

	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, bitangent));
	glEnableVertexAttribArray(4);


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}


Primitive::~Primitive()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void Primitive::CreatObjData(ObjType type)
{
	if (type == cube)
	{
		std::vector<Vertex> vlist;
		Vertex vs[3] = {
			Vertex(-0.5f,-0.5f,0.5f,0,0),
			Vertex(0.5f,-0.5f,0.5f,1,0),
			Vertex(-0.5f,0.5f,0.5f,0,1)
		};
		CalculateTangent(vs);
		for (int i = 0; i < 3; i++)
		{
			vlist.push_back(vs[i]);
		}
		vs[0] = Vertex(-0.5f, 0.5f, 0.5f, 0, 1);
		vs[1] = Vertex(0.5f, -0.5f, 0.5f, 1, 0);
		vs[2] = Vertex(0.5f, 0.5f, 0.5f, 1, 1);
		CalculateTangent(vs);
		for (int i = 0; i < 3; i++)
		{
			vlist.push_back(vs[i]);
		}

		vs[0] = Vertex(0.5f, -0.5f, 0.5f, 0, 0);
		vs[1] = Vertex(0.5f, -0.5f, -0.5f, 1, 0);
		vs[2] = Vertex(0.5f, 0.5f, 0.5f, 0, 1);
		CalculateTangent(vs);
		for (int i = 0; i < 3; i++)
		{
			vlist.push_back(vs[i]);
		}
		vs[0] = Vertex(0.5f, 0.5f, 0.5f, 0, 1);
		vs[1] = Vertex(0.5f, -0.5f, -0.5f, 1, 0);
		vs[2] = Vertex(0.5f, 0.5f, -0.5f, 1, 1);
		CalculateTangent(vs);
		for (int i = 0; i < 3; i++)
		{
			vlist.push_back(vs[i]);
		}

		vs[0] = Vertex(0.5f, -0.5f, -0.5f, 0, 0);
		vs[1] = Vertex(-0.5f, -0.5f, -0.5f, 1, 0);
		vs[2] = Vertex(0.5f, 0.5f, -0.5f, 0, 1);
		CalculateTangent(vs);
		for (int i = 0; i < 3; i++)
		{
			vlist.push_back(vs[i]);
		}
		vs[0] = Vertex(0.5f, 0.5f, -0.5f, 0, 1);
		vs[1] = Vertex(-0.5f, -0.5f, -0.5f, 1, 0);
		vs[2] = Vertex(-0.5f, 0.5f, -0.5f, 1, 1);
		CalculateTangent(vs);
		for (int i = 0; i < 3; i++)
		{
			vlist.push_back(vs[i]);
		}

		vs[0] = Vertex(-0.5f, -0.5f, -0.5f, 0, 0);
		vs[1] = Vertex(-0.5f, -0.5f, 0.5f, 1, 0);
		vs[2] = Vertex(-0.5f, 0.5f, -0.5f, 0, 1);
		CalculateTangent(vs);
		for (int i = 0; i < 3; i++)
		{
			vlist.push_back(vs[i]);
		}
		vs[0] = Vertex(-0.5f, 0.5f, -0.5f, 0, 1);
		vs[1] = Vertex(-0.5f, -0.5f, 0.5f, 1, 0);
		vs[2] = Vertex(-0.5f, 0.5f, 0.5f, 1, 1);
		CalculateTangent(vs);
		for (int i = 0; i < 3; i++)
		{
			vlist.push_back(vs[i]);
		}

		vs[0] = Vertex(-0.5f, 0.5f, 0.5f, 0, 0);
		vs[1] = Vertex(0.5f, 0.5f, 0.5f, 1, 0);
		vs[2] = Vertex(-0.5f, 0.5f, -0.5f, 0, 1);
		CalculateTangent(vs);
		for (int i = 0; i < 3; i++)
		{
			vlist.push_back(vs[i]);
		}
		vs[0] = Vertex(-0.5f, 0.5f, -0.5f, 0, 1);
		vs[1] = Vertex(0.5f, 0.5f, 0.5f, 1, 0);
		vs[2] = Vertex(0.5f, 0.5f, -0.5f, 1, 1);
		CalculateTangent(vs);
		for (int i = 0; i < 3; i++)
		{
			vlist.push_back(vs[i]);
		}

		vs[0] = Vertex(-0.5f, -0.5f, -0.5f, 0, 0);
		vs[1] = Vertex(0.5f, -0.5f, -0.5f, 1, 0);
		vs[2] = Vertex(-0.5f, -0.5f, 0.5f, 0, 1);
		CalculateTangent(vs);
		for (int i = 0; i < 3; i++)
		{
			vlist.push_back(vs[i]);
		}
		vs[0] = Vertex(-0.5f, -0.5f, 0.5f, 0, 1);
		vs[1] = Vertex(0.5f, -0.5f, -0.5f, 1, 0);
		vs[2] = Vertex(0.5f, -0.5f, 0.5f, 1, 1);
		CalculateTangent(vs);
		for (int i = 0; i < 3; i++)
		{
			vlist.push_back(vs[i]);
		}

		dataBuffer = vlist;
	}
	else if (type == plane)
	{
		std::vector<Vertex> vlist;
		Vertex vs[3] = {
			Vertex(-0.5f, 0, 0.5f, 0, 0),
			Vertex(0.5, 0, 0.5f, 1, 0),
			Vertex(-0.5f,0, -0.5f, 0, 1)
		};
		CalculateTangent(vs);
		for (int i = 0; i < 3; i++)
		{
			vlist.push_back(vs[i]);
		}
		vs[0] = Vertex(-0.5f, 0, -0.5f, 0, 1);
		vs[1] = Vertex(0.5f, 0, 0.5f, 1, 0);
		vs[2] = Vertex(0.5f, 0, -0.5f, 1, 1);
		CalculateTangent(vs);
		for (int i = 0; i < 3; i++)
		{
			vlist.push_back(vs[i]);
		}
		dataBuffer = vlist;
	}
}


void Primitive::CalculateTangent(Vertex v[]) {
	// calculate tangent/bitangent vectors of both triangles
	glm::vec3 tangent1, bitangent1;
	// triangle 1
	// ----------
	glm::vec3 edge1 = v[1].position - v[0].position;
	glm::vec3 edge2 = v[2].position - v[0].position;
	glm::vec2 deltaUV1 = v[1].texcoord - v[0].texcoord;
	glm::vec2 deltaUV2 = v[2].texcoord - v[0].texcoord;

	float f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

	tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
	tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
	tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
	tangent1 = glm::normalize(tangent1);

	bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
	bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
	bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
	bitangent1 = glm::normalize(bitangent1);

	vec3 normal = glm::cross(tangent1, bitangent1);
	for (int i = 0; i < 3; i++)
	{
		v[i].tangent = tangent1;
		v[i].bitangent = bitangent1;
		v[i].normal = normal;
	}
}

void Primitive::Draw(Shader shader)
{
	shader.setMat4("_model", modelMat4);
	glBindVertexArray(VAO);
	switch (type)
	{
	case Primitive::cube:
		glDrawArrays(GL_TRIANGLES, 0, 36);
		break;
	case Primitive::plane:
		glDrawArrays(GL_TRIANGLES, 0, 6);
		break;
	default:
		break;
	}

}

void Primitive::SetTransform(glm::vec3 position, glm::vec3 eularAngle, glm::vec3 scale)
{
	Primitive::position = position;
	Primitive::eularAngle = eularAngle;
	Primitive::scale = scale;

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, position);
	model = glm::rotate(model,radians (eularAngle.x), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, radians( eularAngle.y), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, radians( eularAngle.z), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, scale);

	modelMat4 = model;
}
