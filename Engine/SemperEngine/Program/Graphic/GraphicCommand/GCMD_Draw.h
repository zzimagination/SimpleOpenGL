#ifndef __GCMD_DRAW__
#define __GCMD_DRAW__

#include "../GraphicCommand.h"

namespace SemperEngine
{
	namespace Core
	{
		class GDrawCMD : public GraphicCommand
		{
		public:

			RenderOperation operation;

			GraphicVertexInfo vertex;

			ShaderProperty shaderProperty;

			std::vector<GraphicTextureInfo> textures;

			bool useRecord = false;

			std::vector<int> recordID = {};

		private:

			int _setTextureCount = 0;

		public:

			GDrawCMD();

			virtual ~GDrawCMD() override;

			virtual void Excute() override;

		private:

			void SetRecord(int ID);
		};
	}
}
#endif // !__GCMD_DRAW__
