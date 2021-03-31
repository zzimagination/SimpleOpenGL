#include "GCMD_Draw.h"
#include "../GraphicResource.h"
#include "../GraphicRecordManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		GDrawCMD::GDrawCMD()
		{
		}

		GDrawCMD::~GDrawCMD()
		{
		}

		void GDrawCMD::Excute()
		{
			GraphicRenderAPI::SetCullFace(operation.cull);
			GraphicRenderAPI::SetCullMode(operation.cullFace);
			GraphicRenderAPI::SetDepthTest(operation.depth);
			GraphicRenderAPI::SetDepthTestFunc(operation.depthFunc);
			GraphicRenderAPI::SetBlend(operation.blend);
			GraphicRenderAPI::SetBlendFunc();

			auto vertexData = GraphicResource::GetVertexData(vertex.info);
			vector<shared_ptr<GraphicTextureData>> texturesData;
			for (int i = 0; i < textures.size(); i++)
			{
				auto tex = GraphicResource::GetTextureData(textures[i].info);
				texturesData.push_back(tex);
			}

			GraphicRenderAPI::SetVertexData(*vertexData);
			SetShaderProperty(shaderProperty);

			_setTextureCount = 0;

			if (useRecord)
			{
				for (size_t i = 0; i < recordID.size(); i++)
				{
					SetRecord(recordID[i]);
				}
			}

			for (size_t i = 0; i < texturesData.size(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(textures[i].index + _setTextureCount, *(texturesData[i]));
			}

			GraphicRenderAPI::Draw();
		}

		void GDrawCMD::SetRecord(int ID)
		{
			auto record = GraphicRecordManager::GetRecord(ID);
			if (record == nullptr)
			{
				return;
			}
			for (size_t i = 0; i < record->textures.size(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(_setTextureCount, record->textures[i]);
				_setTextureCount++;
			}
		}
	}
}