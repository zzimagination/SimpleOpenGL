//#define UNIT_TEST

#include"pch.h"
#include "GameWindow.h"
#include "GameStart.h"
#include "GameEnd.h"
#include "GameLoop.h"
#include "DebugSystem.h"
#include <fstream>

#include "Test.h"

using namespace SemperEngine;

int main()
{
	setlocale(LC_CTYPE, "");

	//Test::UnitTesting();

	GameStart::Start();
	Core::GameLoop::BeforeLoop();
	Core::GameLoop::MainLoop();
	Core::GameLoop::AfterLoop();
	GameEnd::End();

	return 0;
}

//unsigned int genQuad()
//{
//	// positions
//	glm::vec3 pos1(-1.0f, 1.0f, 0.0f);
//	glm::vec3 pos2(-1.0f, -1.0f, 0.0f);
//	glm::vec3 pos3(1.0f, -1.0f, 0.0f);
//	glm::vec3 pos4(1.0f, 1.0f, 0.0f);
//	// texture coordinates
//	glm::vec2 uv1(0.0f, 1.0f);
//	glm::vec2 uv2(0.0f, 0.0f);
//	glm::vec2 uv3(1.0f, 0.0f);
//	glm::vec2 uv4(1.0f, 1.0f);
//	// normal vector
//	glm::vec3 nm(0.0f, 0.0f, 1.0f);
//
//	// calculate tangent/bitangent vectors of both triangles
//	glm::vec3 tangent1, bitangent1;
//	glm::vec3 tangent2, bitangent2;
//	// triangle 1
//	// ----------
//	glm::vec3 edge1 = pos2 - pos1;
//	glm::vec3 edge2 = pos3 - pos1;
//	glm::vec2 deltaUV1 = uv2 - uv1;
//	glm::vec2 deltaUV2 = uv3 - uv1;
//
//	float f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);
//
//	tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
//	tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
//	tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
//	tangent1 = glm::normalize(tangent1);
//
//	bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
//	bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
//	bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
//	bitangent1 = glm::normalize(bitangent1);
//
//	// triangle 2
//	// ----------
//	edge1 = pos3 - pos1;
//	edge2 = pos4 - pos1;
//	deltaUV1 = uv3 - uv1;
//	deltaUV2 = uv4 - uv1;
//
//	f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);
//
//	tangent2.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
//	tangent2.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
//	tangent2.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
//	tangent2 = glm::normalize(tangent2);
//
//
//	bitangent2.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
//	bitangent2.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
//	bitangent2.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
//	bitangent2 = glm::normalize(bitangent2);
//
//
//	float quadVertices[] = {
//		// positions            // normal         // texcoords  // tangent                          // bitangent
//		pos1.x, pos1.y, pos1.z, nm.x, nm.y, nm.z, uv1.x, uv1.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,
//		pos2.x, pos2.y, pos2.z, nm.x, nm.y, nm.z, uv2.x, uv2.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,
//		pos3.x, pos3.y, pos3.z, nm.x, nm.y, nm.z, uv3.x, uv3.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,
//
//		pos1.x, pos1.y, pos1.z, nm.x, nm.y, nm.z, uv1.x, uv1.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z,
//		pos3.x, pos3.y, pos3.z, nm.x, nm.y, nm.z, uv3.x, uv3.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z,
//		pos4.x, pos4.y, pos4.z, nm.x, nm.y, nm.z, uv4.x, uv4.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z
//	};
//	// configure plane VAO
//	unsigned int quadVAO, quadVBO;
//	glGenVertexArrays(1, &quadVAO);
//	glGenBuffers(1, &quadVBO);
//	glBindVertexArray(quadVAO);
//	glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(3);
//	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(8 * sizeof(float)));
//	glEnableVertexAttribArray(4);
//	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(11 * sizeof(float)));
//
//	return quadVAO;
//}