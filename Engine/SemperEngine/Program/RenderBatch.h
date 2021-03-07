#ifndef __RENDERBATCH__
#define __RENDERBATCH__

#include <vector>
#include <memory>
#include "Common.h"
#include "Mesh.h"
#include "Material.h"
#include "Graphic.h"
#include "CameraObject.h"

namespace SemperEngine {

	namespace Core
	{
		class RenderBatch
		{
		public:

			static GraphicVertexInfo GetVertexInfo(Mesh* mesh);

			static RenderMatrix GetRenderMatrix(Matrix4x4 model, CameraObject* camera);

			static RenderOperation GetOperation(Material* material);

			static ShaderProperty GetShaderProperty(Material* material);

			static std::vector<GraphicTextureInfo> GetTextures(Material* material);

		public:

			bool useRecord = false;

			std::vector<int> recordIDs;

			std::vector<std::string> recordNames;

		public:

			virtual ~RenderBatch();

			virtual void GenerateGraphicResource() = 0;

			virtual void RenderGraphicObject() = 0;

		};

		class ClearBatch : public RenderBatch
		{
		public:

			Color clearColor;

			Graphic::ClearMode clearMode;

		public:

			ClearBatch();

			ClearBatch(Color color, Graphic::ClearMode mode);

			virtual ~ClearBatch() override;

			virtual void RenderGraphicObject() override;

			virtual void GenerateGraphicResource() override;
		};

		class CustomRenderBatch : public RenderBatch
		{
		public:

			Mesh* mesh = nullptr;

			CameraObject* camera = nullptr;

			Material* material = nullptr;

			Matrix4x4 model;

		public:

			virtual ~CustomRenderBatch() override;

			virtual void RenderGraphicObject() override;

			virtual void GenerateGraphicResource() override;
		};

		class ScreenRenderBatch : public RenderBatch
		{
		public:

			Material* material = nullptr;

		public:
			// Í¨¹ý RenderBatch ¼Ì³Ð
			virtual void GenerateGraphicResource() override;

			virtual void RenderGraphicObject() override;
		};
	}
}
#endif // !RENDERBATCH




