#include "ModelLib.h"
#include "tiny_obj_loader.h"
#include <iostream>
#include <string>
#include <fstream>

#pragma warning(disable:6386)
#pragma warning(disable:26451)

namespace SemperEngine
{
	namespace ModelLib
	{
		using namespace std;

		void SetFace(Node& node, tinyobj::attrib_t& attr, vector<tinyobj::index_t>& indices)
		{
			node.size = indices.size();
			node.vertices = new Float3[indices.size()];
			node.uv = new Float2[indices.size()];
			for (auto i = 0; i < indices.size(); i++)
			{
				auto v = indices[i].vertex_index;
				auto t = indices[i].texcoord_index;
				v = v >= 0 ? v : 0;
				t = t >= 0 ? t : 0;
				node.vertices[i].x = attr.vertices[v * 3];
				node.vertices[i].y = attr.vertices[v * 3 + 1];
				node.vertices[i].z = attr.vertices[v * 3 + 2];
				node.uv[i].x = attr.texcoords[t * 2];
				node.uv[i].y = attr.texcoords[t * 2 + 1];
			}
		}

		void SetShape(Model& model, tinyobj::attrib_t& attr, tinyobj::shape_t& shape)
		{
			Node child;
			child.name = shape.name;
			SetFace(child, attr, shape.mesh.indices);
			model.root.children.push_back(child);
		}

		Model LoadObject(string path)
		{
			Model model;
			std::string warn;
			std::string err;

			std::ifstream file(path);
			if (file.fail())
			{
				model.error = "Can't load file";
				return model;
			}

			model.path = path;
			tinyobj::attrib_t attribute;
			std::vector<tinyobj::shape_t> shapes;
			std::vector<tinyobj::material_t> materials;
			auto result = tinyobj::LoadObj(&attribute, &shapes, &materials, &warn, &err, &file);
			if (!result)
			{
				model.warning = warn;
				model.error = err;
				return model;
			}

			model.error = err;
			model.warning = warn;

			for (auto sp = shapes.begin(); sp != shapes.end(); sp++)
			{
				SetShape(model, attribute, *sp);
			}
			return model;
		}
	}
}