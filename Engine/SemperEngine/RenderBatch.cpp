#include "RenderBatch.h"
#include "GraphicDataCenter.h"

namespace SemperEngine
{
	namespace Core
	{
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
				throw "VertexType is screen";
			}
			_mesh = mesh;
		}
		GraphicVertexInfo RenderBatch::GetGraphicVertexInfo()
		{
			if (_vertexType == VertexType::Screen)
			{
				throw "VertexType is screen";
			}
			GraphicVertexInfo info;
			info.info = _mesh->object->graphicDataInfo;
			return info;
		}
		void RenderBatch::SetModelMatrix(Matrix4x4 mat4)
		{
			if (_vertexType == VertexType::Screen)
			{
				throw "VertexType is screen";
			}
			_renderMatrix.model = mat4;
		}

		void RenderBatch::SetViewMatrix(Matrix4x4 mat4)
		{
			if (_vertexType == VertexType::Screen)
			{
				throw "VertexType is screen";
			}
			_renderMatrix.view = mat4;
		}

		void RenderBatch::SetProjectionMatrix(Matrix4x4 mat4)
		{
			if (_vertexType == VertexType::Screen)
			{
				throw "VertexType is screen";
			}
			_renderMatrix.projection = mat4;
		}
		RenderMatrix RenderBatch::GetRenderMatrix()
		{
			if (_vertexType == VertexType::Screen)
			{
				throw "VertexType is screen";
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
	}
}
