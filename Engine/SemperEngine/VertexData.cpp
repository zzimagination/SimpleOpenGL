#include "VertexData.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		VertexData::VertexData()
		{
			vector<Vector3> vertices;
			vertexCount = 0;
			vector<Vector2> uv;
			vector<int> index;
		}
		VertexData::~VertexData()
		{
		}
	}
}