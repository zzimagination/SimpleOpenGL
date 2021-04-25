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
			return obj->renderOperation;
		}

		ShaderProperty RenderBatch::GetShaderProperty(Material* material)
		{
			auto obj = (MaterialObject*)material->GetObject();
			auto pro = obj->shaderProperty;
			return pro;
		}

		std::vector<GraphicTextureInfo> RenderBatch::GetTextures(Material* material)
		{
			vector<GraphicTextureInfo> infos;
			auto source = material->GetTextures();
			for (size_t i = 0; i < source.size(); i++)
			{
				GraphicTextureInfo info;
				info.index = (int)i;
				info.info = ((TextureObject*)source[i]->GetObject())->graphicDataInfo;
				info.name = source[i]->GetObject()->name;
				infos.push_back(info);
			}
			return infos;
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
