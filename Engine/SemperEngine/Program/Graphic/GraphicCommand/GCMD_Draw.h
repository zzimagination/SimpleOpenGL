#ifndef __GCMD_DRAW__
#define __GCMD_DRAW__

#include "../GraphicCommand.h"

namespace Semper
{
	namespace Core
	{
		class GDrawCMD : public GraphicCommand
		{
		public:

			RenderOperation operation;

			std::shared_ptr<ShaderProperty> shaderProperty;

			GraphicVertexData* vertexData = nullptr;

			std::vector<GraphicRecord*> records;

		private:

			int _setTextureCount = 0;

		public:

			GDrawCMD();

			virtual ~GDrawCMD() override;

			virtual void Execute() override;

		private:

			void SetShaderProperty();

			void UseRecords(int &count);

		};
	}
}
#endif // !__GCMD_DRAW__
