#include "ModelLib.h"
#include "tiny_obj_loader.h"
#include <iostream>
#include <string>
#include <fstream>

namespace SemperEngine
{
	namespace ModelLib
	{
		using namespace std;

		void SetFace(Model& model, tinyobj::attrib_t& attr, vector<tinyobj::index_t>& indices)
		{
			for (auto i = indices.begin(); i != indices.end(); i++)
			{
				auto v = i->vertex_index;
				auto t = i->texcoord_index;
				v = v >= 0 ? v : 0;
				t = t >= 0 ? t : 0;
				model.vertices.push_back(attr.vertices[v]);
				model.uv.push_back(attr.texcoords[t]);
			}
		}

		void SetShape(Model& model, tinyobj::attrib_t& attr, tinyobj::shape_t& shape)
		{
			Model child;
			child.name = shape.name;
			SetFace(child, attr, shape.mesh.indices);
			model.children.push_back(child);
		}

		Model LoadObject(string path)
		{
			std::string warn;
			std::string err;
			std::ifstream file(path);

			if (file.fail())
			{
				Model model;
				model.error.append("Can't find the file ");
				model.error.append(path);
				return model;
			}

			tinyobj::attrib_t attribute;
			std::vector<tinyobj::shape_t> shapes;
			std::vector<tinyobj::material_t> materials;
			auto result = tinyobj::LoadObj(&attribute, &shapes, &materials, &warn, &err, &file);
			if (!result)
			{
				Model model;
				model.error = err;
				return model;
			}

			Model model;
			if (shapes.size() == 1)
			{
				model.name = shapes[0].name;
				SetFace(model, attribute, shapes[0].mesh.indices);
				return model;
			}

			for (auto sp = shapes.begin(); sp != shapes.end(); sp++)
			{
				SetShape(model, attribute, *sp);
			}
			return model;
		}
	}
}