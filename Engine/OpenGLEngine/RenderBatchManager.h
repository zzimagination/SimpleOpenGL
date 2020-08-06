#ifndef RENDERBATCH_MANAGER
#define RENDERBATCH_MANAGER

#include <vector>

using namespace std;

class RenderObject;
class Texture;
class RenderVertex;
class RenderBatch;
class Camera;
class TextureData;
class VertexData;

class RenderBatchManager
{
public:

	static vector<RenderBatch> batchs;

public:

	static void GenerateBatchs(vector<RenderObject*> renderObjects);

	static void ClearBatchs();

	static void DrawBatchs(Camera* camera);

private:

	static VertexData* GetVertexData(RenderVertex* v);

	static vector<TextureData*> GetTextureData(vector<Texture*> tex);

};


#endif // !RENDERBATCH_MANAGER
