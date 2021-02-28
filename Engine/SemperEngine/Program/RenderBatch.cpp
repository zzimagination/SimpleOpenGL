#include "RenderBatch.h"
#include "Debug.h"
#include "GraphicRenderer.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;


		GraphicVertexInfo RenderBatch::GetVertexInfo(Mesh* mesh)
		{
			GraphicVertexInfo info;
			info.name = mesh->GetObject()->name;
			info.info = mesh->GetObject()->graphicDataInfo;
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
			return material->GetObject()->renderOperation;
		}

		ShaderProperty RenderBatch::GetShaderProperty(Material* material)
		{
			return material->GetObject()->shaderProperty;
		}

		std::vector<GraphicTextureInfo> RenderBatch::GetTextures(Material* material)
		{
			vector<GraphicTextureInfo> infos;
			auto source = material->GetTextures();
			for (size_t i = 0; i < source.size(); i++)
			{
				GraphicTextureInfo info;
				info.index = (int)i;
				info.info = source[i]->GetObject()->graphicDataInfo;
				info.name = source[i]->GetObject()->name;
				infos.push_back(info);
			}
			return infos;
		}

		RenderBatch::~RenderBatch()
		{
		}

		void RenderBatch::GenerateGraphicResource()
		{
		}

		void RenderBatch::RenderGraphicObject()
		{
		}

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
			_mesh = mesh;
		}
		GraphicVertexInfo RenderBatch::GetGraphicVertexInfo()
		{
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

		ClearBatch::ClearBatch(Color color, Graphic::ClearMode mode) : clearColor(color), clearMode(mode)
		{
		}

		ClearBatch::~ClearBatch()
		{
		}

		void ClearBatch::RenderGraphicObject()
		{
			GraphicRenderer::Clear(clearColor, clearMode);
		}

		CustomRenderBatch::~CustomRenderBatch()
		{
		}
		void CustomRenderBatch::RenderGraphicObject()
		{
			auto v = GetVertexInfo(mesh);
			auto operation = GetOperation(material);
			auto matrix = GetRenderMatrix(model, camera);
			auto shaderProperty = GetShaderProperty(material);
			auto textures = GetTextures(material);
			GraphicRenderer::Render(v, operation, matrix, shaderProperty, textures);
		}
		void CustomRenderBatch::GenerateGraphicResource()
		{
			mesh->GetObject()->CreateGraphicResource();
			material->GetObject()->CreateGraphicResource();
		}
	}
}
