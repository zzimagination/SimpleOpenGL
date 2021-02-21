#include "TextureObject.h"
#include "ResourceObjectCenter.h"
#include "GraphicResource.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		TextureObject* TextureObject::Create(int width, int height)
		{
			auto obj = new TextureObject;
			obj->width = width;
			obj->height = height;
			obj->pixels = ArrayList<ColorByte>((size_t)width * height * 4);
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
			DeleteGraphicResource();
		}

		void TextureObject::EndModify()
		{
			DeleteGraphicResource();
		}

		void TextureObject::CreateGraphicResource()
		{
			if (graphicBind)
			{
				return;
			}
			graphicBind = true;
			GraphicTextureResource resource;
			resource.pixels = &pixels;
			resource.width = width;
			resource.height = height;
			switch (filter)
			{
			case ResourceConfig::TextureFilter::Linear:
				resource.filter = Graphic::TextureFilter::Linear;
				break;
			case ResourceConfig::TextureFilter::Nearest:
				resource.filter = Graphic::TextureFilter::Nearest;
				break;
			}
			graphicDataInfo = GraphicResource::AddTextureData(resource);
		}

		void TextureObject::DeleteGraphicResource()
		{
			if (!graphicBind)
			{
				return;
			}
			graphicBind = false;
			GraphicResource::RemoveTextureData(graphicDataInfo);
			graphicDataInfo = GraphicDataInfo();
		}


		TextureObject* TextureObject::Copy()
		{
			auto obj = new TextureObject;
			obj->width = this->width;
			obj->height = this->height;
			obj->pixels.Resize(pixels.Size());
			obj->pixels.Copy(pixels.DataPtr());
			return obj;
		}
	}
}