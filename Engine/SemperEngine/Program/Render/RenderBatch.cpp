#include "RenderBatch.h"
#include "RenderRecordManager.h"
#include "../Graphic/GraphicRenderer.h"
#include "../ResourceInternal.h"
#include "../Debug.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

		GraphicVertexInfo RenderBatch::GetVertexInfo(Mesh* mesh)
		{
			GraphicVertexInfo info;
			info.name = mesh->GetObject()->name;
			info.info = ((MeshObject*)mesh->GetObject())->graphicDataInfo;
			return info;
		}

		RenderMatrix RenderBatch::GetRenderMatrix(Matrix4x4 model, CameraObject* camera)
		{
			RenderMatrix matrix;
			matrix.model = model;
			matrix.projection = camera->projectMatrix;
			matrix.view = camera->viewMatrix;
			return matrix;
		}

		RenderOperation RenderBatch::GetOperation(Material* material)
		{
			auto obj = (MaterialObject*)material->GetObject();
			RenderOperation result;
			result.depth = obj->depth > 0;
			if (obj->depth == 0)
			{
				result.depth = false;
			}
			else if(obj->depth == 1)
			{
				result.depth = true;
				result.depthFunc = Graphic::DepthFunc::LEqual;
			}
			else if (obj->depth == 2)
			{
				result.depth = true;
				result.depthFunc = Graphic::DepthFunc::GEqual;
			}
			else if (obj->depth == 3)
			{
				result.depth = true;
				result.depthFunc = Graphic::DepthFunc::Always;
			}
			else if (obj->depth == 4)
			{
				result.depth = true;
				result.depthFunc = Graphic::DepthFunc::Never;
			}
			if (obj->cull == 0)
			{
				result.cull = false;
			}
			else if (obj->cull == 1)
			{
				result.cull = true;
				result.cullFace = Graphic::CullFace::Back;
			}
			else if (obj->cull == 2)
			{
				result.cull = true;
				result.cullFace = Graphic::CullFace::Front;
			}
			result.blend = obj->blend;
			return result;
		}

		GraphicDataInfo RenderBatch::TextureConvert(std::shared_ptr<Texture> tex)
		{
			auto obj = (TextureObject*)tex->GetObject();
			return obj->graphicDataInfo;
		}

		std::shared_ptr<ShaderProperty> RenderBatch::GetShaderProperty(Material* material)
		{
			auto materialObject = (MaterialObject*)material->GetObject();
			auto shaderProperty = shared_ptr<ShaderProperty>(new ShaderProperty());
			shaderProperty->shaderID = materialObject->shaderID;
			shaderProperty->floatProperty = materialObject->floatProperties;
			shaderProperty->vector2Property = materialObject->float2Properties;
			shaderProperty->vector3Property = materialObject->float3Properties;
			shaderProperty->vector4Property = materialObject->float4Properties;
			shaderProperty->matrix4x4Property = materialObject->matrix4x4Properties;
			auto texs = materialObject->textureList.ToVector();
			for (auto i =0; i < texs.size(); i++)
			{
				auto tex = materialObject->textureProperties[texs[i]];
				auto info = TextureConvert(tex);
				shaderProperty->textureProperty.push_back(info);
			}
			return shaderProperty;
		}

		RenderBatch::~RenderBatch()
		{
		}

		void RenderBatch::SetRecord(std::string key, CameraObject* camera)
		{
			auto record = RenderRecordManager::GetRecord(key, camera);
			_graphicRecords.push_back(record.graphicID);
		}
	}
}
