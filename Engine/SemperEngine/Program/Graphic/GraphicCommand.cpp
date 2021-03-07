#include "../GraphicCommand.h"
#include "../GraphicRenderAPI.h"
#include "GraphicRecordManager.h"
#include "../GameSetting.h"

namespace SemperEngine
{
	namespace Core
	{
		void GraphicCommand::SetShaderProperty(ShaderProperty p)
		{
			GraphicRenderAPI::SetShader(p.name);
			for (auto i = p.floatProperty.begin(); i != p.floatProperty.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(i->first, i->second);
			}
			for (auto i = p.vector2Property.begin(); i != p.vector2Property.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(i->first, i->second);
			}
			for (auto i = p.vector3Property.begin(); i != p.vector3Property.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(i->first, i->second);
			}
			for (auto i = p.vector4Property.begin(); i != p.vector4Property.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(i->first, i->second);
			}
			for (auto i = p.colorProperty.begin(); i != p.colorProperty.end(); i++)
			{
				auto f = i->second.ToFloat4();
				GraphicRenderAPI::SetShaderProperty(i->first, f);
			}
			for (auto i = p.matrix4x4Property.begin(); i != p.matrix4x4Property.end(); i++)
			{
				GraphicRenderAPI::SetShaderProperty(i->first, i->second);
			}
		}

		GCMD_CreateRecord::GCMD_CreateRecord()
		{
			record = GraphicRecordManager::CreateRecord(name);
			record->width = GameSetting::windowWidth;
			record->height = GameSetting::windowHeight;
		}

		GCMD_CreateRecord::~GCMD_CreateRecord()
		{
		}

		void GCMD_CreateRecord::Excute()
		{
			GraphicRecordManager::currentRecord = record;
			GraphicRenderAPI::CreateRecord(record);
		}
		GCMD_StopRecord::GCMD_StopRecord()
		{
		}
		GCMD_StopRecord::~GCMD_StopRecord()
		{
		}
		void GCMD_StopRecord::Excute()
		{
			GraphicRenderAPI::StopRecord(GraphicRecordManager::currentRecord);
			GraphicRecordManager::lastRecord = GraphicRecordManager::currentRecord;
			GraphicRecordManager::currentRecord = nullptr;
		}
		GCMD_ClearRecords::~GCMD_ClearRecords()
		{
			GraphicRecordManager::Clear();
		}
		void GCMD_ClearRecords::Excute()
		{
			auto list = GraphicRecordManager::GetExecuteList();
			for (auto r = list.begin(); r != list.end(); r++)
			{
				GraphicRenderAPI::DeleteRecord((*r));
			}
		}
		GCMD_DrawRecord::~GCMD_DrawRecord()
		{
		}
		void GCMD_DrawRecord::Excute()
		{
			GraphicRenderAPI::SetCullFace(operation.cull);
			GraphicRenderAPI::SetCullMode(operation.cullFace);
			GraphicRenderAPI::SetDepthTest(operation.depth);
			GraphicRenderAPI::SetDepthTestFunc(operation.depthFunc);
			GraphicRenderAPI::SetBlend(operation.blend);
			GraphicRenderAPI::SetBlendFunc();

			auto vertexData = GraphicResource::GetVertexData(vertex.info);
			GraphicRenderAPI::SetVertexData(*vertexData);
			SetShaderProperty(shaderProperty);
			GraphicRenderAPI::SetShaderProperty(0, GraphicRecordManager::lastRecord->textures[0]);
			GraphicRenderAPI::Draw();
		}
	}
}