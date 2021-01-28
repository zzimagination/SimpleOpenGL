#include "ResourceModelLibrary.h"
#include "NativeResource.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		ResourceModelLibrary::~ResourceModelLibrary()
		{
		}


		void AddMesh(ModelLib::Node& n1, ModelObject::Node& n2)
		{
			auto meshObject = new MeshObject();
			meshObject->name = n1.name;
			meshObject->data = unique_ptr<VertexData>(new VertexData);
			auto size = n1.size;
			meshObject->data->vertices = ArrayList<Float3>((Float3*)n1.vertices, size);
			meshObject->data->uv = ArrayList<Float2>((Float2*)n1.uv, size);
			n2.mesh = meshObject;
		}

		void AddNode(ModelLib::Node& n1, ModelObject::Node& n2)
		{
			for (size_t i = 0; i < n1.children.size(); i++)
			{
				ModelObject::Node node;
				AddMesh(n1.children[i], node);
				AddNode(n1.children[i], node);
				n2.children.push_back(node);
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
			object->filePath = path;
			if (resource.root.size != 0)
			{
				AddMesh(resource.root, object->root);
			}
			AddNode(resource.root, object->root);
			object->id = _library.Add(object);
			object->Use();
			return object;
		}
	}
}