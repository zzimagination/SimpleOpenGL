#ifndef TEXTUREDATA_LIST
#define TEXTUREDATA_LIST

#include <map>
class Texture;
class TextureData;

using namespace std;

class TextureDataList
{
private:

	static map<Texture*, TextureData*> dataMap;

public:

	static TextureData* GetData(Texture* tex);
};


#endif // !TEXTUREDATA_LIST

