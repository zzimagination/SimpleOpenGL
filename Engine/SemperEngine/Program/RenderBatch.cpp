#include "RenderBatch.h"
#include "Debug.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		void RenderBatch::SetVertexType(VertexType type)
		{
			this->_vertexType = type;
			if (type == VertexType::Screen)
			{
				_mesh.reset();
			}
		}
		RenderBatch::VertexType RenderBatch::GetVertexType()
		{
			return this->_vertexType;
		}
		void RenderBatch::SetMesh(std::shared_ptr<Mesh> mesh)
		{
			if (_vertexType == VertexType::Screen)
			{
				Debug::LogError("VertexType is screen");
			}
			_mesh = mesh;
		}
		GraphicVertexInfo RenderBatch::GetGraphicVertexInfo()
		{
			if (_vertexType == VertexType::Screen)
			{
				Debug::LogError("VertexType is screen");
			}

			GraphicVertexInfo info;
			info.info = _mesh->GetObject()->graphicDataInfo;
			return info;
		}
		void RenderBatch::SetModelMatrix(Matrix4x4 mat4)
		{
			if (_vertexType == VertexType::Screen)
			{
				Debug::LogError("VertexType is screen");
			}
			_renderMatrix.model = mat4;
		}

		void RenderBatch::SetViewMatrix(Matrix4x4 mat4)
		{
			if (_vertexType == VertexType::Screen)
			{
				Debug::LogError("VertexType is screen");
			}
			_renderMatrix.view = mat4;
		}

		void RenderBatch::SetProjectionMatrix(Matrix4x4 mat4)
		{
			if (_vertexType == VertexType::Screen)
			{
				Debug::LogError("VertexType is screen");
			}
			_renderMatrix.projection = mat4;
		}
		RenderMatrix RenderBatch::GetRenderMatrix()
		{
			if (_vertexType == VertexType::Screen)
			{
				Debug::LogError("VertexType is screen");
			}
			return _renderMatrix;
		}

		void RenderBatch::SetMaterial(std::shared_ptr<Material> material)
		{
			_material = material;
		}
		std::shared_ptr<Material> RenderBatch::GetMaterial()
		{
			return _material;
		}
		std::vector<GraphicTextureInfo> RenderBatch::GetGraphicTextureInfos()
		{
			vector<GraphicTextureInfo> gtextures;
			auto textures = _material->GetTextures();
			for (int j = 0; j < textures.size(); j++)
			{
				auto index = j;
				auto info = textures[j]->GetObject()->graphicDataInfo;
				GraphicTextureInfo tmp;
				tmp.index = index;
				tmp.info = info;
				gtextures.push_back(tmp);
			}
			return gtextures;
		}
	}
}
