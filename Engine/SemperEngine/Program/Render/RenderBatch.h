#ifndef __RENDERBATCH__
#define __RENDERBATCH__

#include <vector>
#include <memory>
#include "../Common.h"
#include "../ResourceInternal.h"
#include "../Graphic/Graphic.h"
#include "../Graphic/GraphicRenderer.h"
#include "../RenderObject.h"
#include "RenderRecordManager.h"

namespace Semper {

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

		protected:

			std::vector<int> _graphicRecords;

		public:

			virtual ~RenderBatch();

			virtual void GenerateGraphicResource() = 0;

			virtual void RenderGraphicObject() = 0;

			void SetRecord(std::string key, CameraObject* camera);

		};
	}
}
#endif // !RENDERBATCH


#include "RenderBatch/ClearBatch.h"
#include "RenderBatch/CustomRenderBatch.h"
#include "RenderBatch/ScreenRenderBatch.h"


