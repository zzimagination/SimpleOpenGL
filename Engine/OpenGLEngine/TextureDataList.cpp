#include "TextureDataList.h"
#include "TextureData.h"
#include "Texture.h"

map<Texture*, TextureData*> TextureDataList::dataMap;

TextureData * TextureDataList::GetData(Texture * tex)
{
	if (dataMap.count(tex))
	{
		return dataMap[tex];
	}
	else {
		TextureData* data = new TextureData(tex);
		dataMap[tex] = data;
		return data;
	}
}
