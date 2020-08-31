#include "GraphicDataCenter.h"

namespace SemperEngine
{
	 std::map<RenderVertexData*, GraphicVertexData*> GraphicDataCenter::vertexDatas;

	 std::map<Texture*, GraphicTextureData*> GraphicDataCenter::textureDatas;

	 GraphicVertexData * GraphicDataCenter::GetVertexData(RenderVertexData* data)
	 {
		 if (vertexDatas.count(data))
		 {
			 return vertexDatas[data];
		 }
		 else 
		 {
			 GraphicVertexData* result = new GraphicVertexData(data);
			 vertexDatas[data] = result;
			 return result;
		 }
	 }

	 GraphicTextureData * GraphicDataCenter::GetTextureData(Texture* tex)
	 {
		 if (textureDatas.count(tex))
		 {
			 return textureDatas[tex];
		 }
		 else
		 {
			 auto result = new GraphicTextureData(tex);
			 textureDatas[tex] = result;
			 return result;
		 }
	 }
}