#include "TextureObject.h"
#include "ResourceDataCenter.h"
#include "ResourceObjectCenter.h"
#include "GraphicDataCenter.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		TextureObject* TextureObject::Create()
		{
			auto obj = new TextureObject;
			obj->resourcePackage = ResourceDataCenter::CreateTexture();
			return obj;
		}

		TextureObject::TextureObject()
		{
		}

		TextureObject::~TextureObject()
		{
		}

		void TextureObject::EndCreate()
		{
			graphicDataInfo = GraphicDataCenter::AddTextureData(resourcePackage.GetResource());
		}

		void TextureObject::EndDelete()
		{
			resourcePackage.Dispose();
			GraphicDataCenter::RemoveTextureData(graphicDataInfo);
		}

		void TextureObject::EndModify()
		{
			GraphicDataCenter::RemoveTextureData(graphicDataInfo);
			graphicDataInfo = GraphicDataCenter::AddTextureData(resourcePackage.GetResource());
		}

		void TextureObject::ColorBytes(ArrayList<ColorByte> data)
		{
			resourcePackage.GetResource()->pixels = data;
			Modify();
		}

		TextureObject* TextureObject::Copy()
		{
			auto package = ResourceDataCenter::CopyTexture(resourcePackage);
			auto obj = new TextureObject;
			obj->resourcePackage = package;
			return obj;
		}

		ArrayList<ColorByte> TextureObject::ColorBytes()
		{
			return resourcePackage.GetResource()->pixels;
		}
	}
}