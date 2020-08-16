#include<glad/glad.h>

#include "VertexData.h"
#include "RenderObject.h"
#include "RenderVertex.h"
namespace SemperEngine {
	VertexData::VertexData(RenderVertex* renderVertex)
	{
		VAO = 0;
		VBO = 0;
		EBO = 0;
		BindData(renderVertex->GetVertices(),
			renderVertex->VertexCount(),
			renderVertex->GetIndices(),
			renderVertex->GetUV());
	}

	VertexData::~VertexData()
	{
		glDeleteBuffers(1, &EBO);//注意顺序
		glDeleteBuffers(1, &VBO);
		glDeleteVertexArrays(1, &VAO);
	}

	void VertexData::BindData(Vector3* vertices, int count, int* index, Vector2* uv)
	{
		if (count >= 4)
		{
			_pointCount = count / 4 * 6;
			if (count / 4 * 6 != _pointCount)
			{
				throw "indexSize is not match indexSize vertexData";
			}
		}
		else
		{
			_pointCount = count;
		}

		int verticesSize = count * sizeof(Vector3);
		int uvSize = count * sizeof(Vector2);
		int indexSize = _pointCount * sizeof(int);
		int totalSize = verticesSize + uvSize + indexSize;

		if (verticesSize == 0 || indexSize == 0)
		{
			throw "vertexData is null";
		}

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

		glBufferData(GL_ARRAY_BUFFER, totalSize, 0, GL_STATIC_DRAW);//首先执行这个
		int offset = 0;
		glBufferSubData(GL_ARRAY_BUFFER, offset, verticesSize, vertices);
		offset += verticesSize;
		if (uvSize > 0) {
			glBufferSubData(GL_ARRAY_BUFFER, offset, uvSize, uv);
			offset += uvSize;
		}

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize, index, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vector3), (void*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vector2), (void*)verticesSize);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
		// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
		glBindVertexArray(0);
	}

	int VertexData::GetCount()
	{
		return _pointCount;
	}

	void VertexData::UseData()
	{
		glBindVertexArray(VAO);
	}
}