#include "ResourceModelLibrary.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		ResourceModelLibrary::~ResourceModelLibrary()
		{
		}


		void ResourceModelLibrary::AddMesh(ModelLib::Node& native, ModelObject::Node& game, std::string path)
		{
			if (native.size == 0)
			{
				return;
			}
			auto meshObject = new MeshObject();
			meshObject->name = native.name;
			meshObject->filePath = path;
			auto size = native.size;
			meshObject->vertices = ArrayList<Float3>((Float3*)native.vertices, size);
			meshObject->uv = ArrayList<Float2>((Float2*)native.uv, size);
			game.mesh = meshObject;
		}

		void ResourceModelLibrary::AddNode(ModelLib::Node& native, ModelObject::Node& game, std::string path)
		{
			AddMesh(native, game, path);
			for (size_t i = 0; i < native.children.size(); i++)
			{
				ModelObject::Node node;
				auto newPath = path + "/";
				newPath += native.children[i].name;
				AddNode(native.children[i], node, newPath);
				game.children.push_back(node);
			}
		}

		ModelObject* ResourceModelLibrary::Load(std::string path)
		{
			for (int i = 0; i < (int)_library.Size(); i++)
			{
				if (_library.IsEmpty(i))
				{
					continue;
				}
				if (_library[i]->filePath == path)
				{
					return _library[i];
				}
			}

			auto resource = NativeResource::LoadModel(path);
			auto object = new ModelObject();
			object->filePath = resource.path;
			AddNode(resource.root, object->root, resource.path);
			object->id = _library.Add(object);
			object->Use();
			return object;
		}
	}
}