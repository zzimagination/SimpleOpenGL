#include "ResourceObjectContainer.h"
#include "GraphicDataCenter.h"
#include "ResourceDataCenter.h"
#include "Debug.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		std::shared_ptr<TextureObject> TextureObjectContainer::Create()
		{
			auto package = ResourceDataCenter::CreateTexture();
			auto obj = shared_ptr<TextureObject>(new TextureObject(false, _setting));
			obj->Use();
			obj->resourcePackage = package;
			_newObjects.push_back(obj);
			return obj;
		}

		std::shared_ptr<TextureObject> TextureObjectContainer::Load(std::string file)
		{
			auto package = ResourceDataCenter::LoadTexture(file);
			auto obj = shared_ptr<TextureObject>(new TextureObject(false, _setting));
			obj->Use();
			obj->resourcePackage = package;
			obj->filePath = file;
			_newObjects.push_back(obj);
			return obj;
		}

		std::shared_ptr<TextureObject> TextureObjectContainer::LoadSave(std::string file)
		{
			auto package = ResourceDataCenter::LoadTexture(file);
			auto obj = shared_ptr<TextureObject>(new TextureObject(true, _setting));
			obj->Use();
			obj->resourcePackage = package;
			obj->filePath = file;
			_newObjects.push_back(obj);
			AddObject(obj);
			return obj;
		}

		std::shared_ptr<TextureObject> TextureObjectContainer::Find(std::string file)
		{
			auto obj = GetObject(file);
			if (obj != nullptr)
			{
				obj->Use();
			}
			return obj;
		}

		void TextureObjectContainer::Delete(std::shared_ptr<TextureObject> obj)
		{
			if (obj->Dispose() > 0)
			{
				return;
			}
			obj->resourcePackage.Dispose();
			if (obj->IsShared())
			{
				RemoveObject(obj->id);
			}
			for (int i = 0; i < _newObjects.size(); i++)
			{
				if (obj == _newObjects[i])
				{
					_newObjects.erase(_newObjects.begin() + i);
					return;
				}
			}
			_deleteObjects.push_back(obj);
		}

		std::shared_ptr<TextureObject> TextureObjectContainer::Copy(std::shared_ptr<TextureObject> resourceObject)
		{
			auto package = ResourceDataCenter::CopyTexture(resourceObject->resourcePackage);
			auto obj = shared_ptr<TextureObject>(new TextureObject(false));
			obj->resourcePackage = package;
			obj->Use();
			_newObjects.push_back(obj);
			return obj;
		}

		void TextureObjectContainer::EndDelete(std::shared_ptr<TextureObject> obj)
		{
			GraphicDataCenter::RemoveTextureData(obj->graphicDataInfo);
		}

		void TextureObjectContainer::EndCreate(std::shared_ptr<TextureObject> obj)
		{
			auto info = GraphicDataCenter::AddTextureData(obj->resourcePackage.GetResource());
			obj->graphicDataInfo = info;
		}

		std::shared_ptr<MeshObject> MeshObjectContainer::Create()
		{
			auto package = ResourceDataCenter::CreateVertexData();
			auto obj = shared_ptr<MeshObject>(new MeshObject(false, _setting));
			obj->Use();
			obj->resourcePackage = package;
			_newObjects.push_back(obj);
			return obj;
		}

		std::shared_ptr<MeshObject> MeshObjectContainer::CreateCube()
		{
			auto package = ResourceDataCenter::CreateCube();
			auto obj = shared_ptr<MeshObject>(new MeshObject(false, _setting));
			obj->Use();
			obj->resourcePackage = package;
			_newObjects.push_back(obj);
			return obj;
		}

		void MeshObjectContainer::Delete(std::shared_ptr<MeshObject> obj)
		{
			if (obj->Dispose() > 0)
			{
				return;
			}
			obj->resourcePackage.Dispose();
			if (obj->IsShared())
			{
				RemoveObject(obj->id);
			}
			for (int i = 0; i < _newObjects.size(); i++)
			{
				if (obj == _newObjects[i])
				{
					_newObjects.erase(_newObjects.begin() + i);
					return;
				}
			}
			_deleteObjects.push_back(obj);
		}

		std::shared_ptr<MeshObject> MeshObjectContainer::Copy(std::shared_ptr<MeshObject> resourceObject)
		{
			auto package = ResourceDataCenter::CopyVertexData(resourceObject->resourcePackage);
			auto obj = shared_ptr<MeshObject>(new MeshObject(false));
			obj->resourcePackage = package;
			obj->Use();
			_newObjects.push_back(obj);
			return obj;
		}

		void MeshObjectContainer::EndDelete(std::shared_ptr<MeshObject> obj)
		{
			GraphicDataCenter::RemoveVertexData(obj->graphicDataInfo);
		}

		void MeshObjectContainer::EndCreate(std::shared_ptr<MeshObject> obj)
		{
			auto info = GraphicDataCenter::AddVertexData(obj->resourcePackage.GetResource());
			obj->graphicDataInfo = info;
		}

	}
}