#include "VertexData.h"
#include "Debug.h"
#include "GraphicDataCenter.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		VertexData::VertexData()
		{
			_isPackage = false;
			vertexCount = 0;
		}

		VertexData::~VertexData()
		{
			if (_isPackage)
			{
				GraphicDataCenter::RemoveVertexData(this->package);
			}
		}
		void VertexData::Package(ResourcePackage<VertexData> mine)
		{
			if (mine.GetResource() != this)
			{
				Debug::Log("not mine");
				throw "not mine";
			}
			this->package = mine;
			GraphicDataCenter::AddVertexData(this->package);
			_isPackage = true;
		}
	}
}