#include "VertexDataList.h"

map<RenderVertex*, VertexData*> VertexDataList::dataMap;

VertexData * VertexDataList::GetVertexData(RenderVertex * value)
{
	if (dataMap.count(value))
	{
		return dataMap[value];
	}
	else
	{
		VertexData* data = new VertexData(value);
		dataMap[value] = data;
		return data;
	}
}
