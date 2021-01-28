#include "TextureObject.h"
#include "ResourceObjectCenter.h"
#include "GraphicDataCenter.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		TextureObject* TextureObject::Create(int width, int height)
		{
			auto obj = new TextureObject;
			obj->data = unique_ptr<TextureData>(new TextureData);
			obj->data->width = width;
			obj->data->height = height;
			obj->data->pixels = ArrayList<ColorByte>((size_t)width * height * 4);
			return obj;
		}

		TextureObject::TextureObject()
		{
		}

		TextureObject::~TextureObject()
		{
		}

		void TextureObject::EndDelete()
		{
			if (graphicBind)
			{
				graphicBind = false;
				GraphicResource::RemoveTextureData(graphicDataInfo);
			}
		}

		void TextureObject::EndModify()
		{
			if (graphicBind)
			{
				graphicBind = false;
				GraphicResource::RemoveTextureData(graphicDataInfo);
			}
		}

		void TextureObject::ColorBytes(ArrayList<ColorByte> data)
		{
			this->data->pixels = data;
			Modify();
		}

		TextureObject* TextureObject::Copy()
		{
			auto obj = new TextureObject;
			auto data = this->data->Copy();
			obj->data = unique_ptr<TextureData>(data);
			return obj;
		}

		ArrayList<ColorByte> TextureObject::ColorBytes()
		{
			return data->pixels;
		}
	}
}