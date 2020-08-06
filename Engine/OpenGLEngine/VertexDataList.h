#ifndef VERTEXDATA_LIST
#define VERTEXDATA_LIST
#include <map>
#include "RenderVertex.h"
#include "VertexData.h"

class VertexDataList {

private:

	static map<RenderVertex*, VertexData*> dataMap;

public:

	static VertexData* GetVertexData(RenderVertex* value);

};

#endif // !VERTEXDATA_LIST
