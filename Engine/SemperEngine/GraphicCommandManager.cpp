#include "GraphicCommandManager.h"
#include "GraphicDataCenter.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		std::vector<GraphicCommand*> GraphicCommandManager::resources;

		std::vector<GraphicCommand*> GraphicCommandManager::front_DrawCommands;
		std::vector<GraphicCommand*> GraphicCommandManager::front_Setting;
		std::vector<GraphicCommand*> GraphicCommandManager::back_DrawCommands;
		std::vector<GraphicCommand*> GraphicCommandManager::back_setting;

		void GraphicCommandManager::Render()
		{
			auto commands = front_Setting;
			for (int i = 0; i < commands.size(); i++)
			{
				commands[i]->Excute();
				delete commands[i];
			}

			commands = front_DrawCommands;
			for (int i = 0; i < commands.size(); i++)
			{
				commands[i]->Excute();
				delete commands[i];
			}
		}

		void GraphicCommandManager::Resource()
		{
			auto commands = resources;
			for (int i = 0; i < commands.size(); i++)
			{
				commands[i]->Excute();
				delete commands[i];
			}
		}

		void GraphicCommandManager::SwapCommands()
		{
			front_DrawCommands = back_DrawCommands;
			front_Setting = back_setting;
			back_DrawCommands.clear();
			back_setting.clear();

			resources.clear();
		}

		void GraphicCommandManager::AddVertexBuffer(VertexCommandData data)
		{
			auto cmd = new  GVertexBufferCMD(data);
			resources.push_back(cmd);
		}

		void GraphicCommandManager::ClearVertexBuffer(VertexCommandData data)
		{
			auto cmd = new  GVertexBufferClearCMD(data);
			resources.push_back(cmd);
		}

		void GraphicCommandManager::AddTextureBuffer(TextureCommandData data)
		{
			auto cmd = new GTextureBufferCMD(data);
			resources.push_back(cmd);
		}

		void GraphicCommandManager::ClearTextureBuffer(TextureCommandData data)
		{
			auto cmd = new  GTextureBufferClearCMD(data);
			resources.push_back(cmd);
		}

		void GraphicCommandManager::DrawScreen(RenderBatch& batch)
		{
			auto cmd = new GDrawScreen();
			cmd->vertexData = GraphicDataCenter::screenVertex;
			cmd->SetShaderProperty(batch.material);
			back_DrawCommands.push_back(cmd);
		}

		void GraphicCommandManager::Draw(RenderBatch& batch)
		{
			auto cmd = new GDrawCMD();
			cmd->vertexData = GraphicDataCenter::GetVertexCommandData(batch.vertexData);
			cmd->shader = batch.material->shader;
			cmd->modelMatrix = batch.modelMatrix;
			cmd->viewMatrix = batch.viewMatrix;
			cmd->projectionMatrix = batch.projectionMatrix;
			auto fp = &batch.material->shaderProperty.floatProperty;
			for (auto i = fp->begin(); i != fp->end(); i++)
			{
				cmd->floatNames.push_back(i->first);
				cmd->floatValues.push_back(i->second);
			}
			auto v2p = &batch.material->shaderProperty.vector2Property;
			for (auto i = v2p->begin(); i != v2p->end(); i++)
			{
				cmd->vec2Names.push_back(i->first);
				cmd->vec2Values.push_back(i->second);
			}
			auto v3p = &batch.material->shaderProperty.vector3Property;
			for (auto i = v3p->begin(); i != v3p->end(); i++)
			{
				cmd->vec3Names.push_back(i->first);
				cmd->vec3Values.push_back(i->second);
			}
			auto v4p = &batch.material->shaderProperty.vector4Property;
			for (auto i = v4p->begin(); i != v4p->end(); i++)
			{
				cmd->vec4Names.push_back(i->first);
				cmd->vec4Values.push_back(i->second);
			}
			auto m4p = &batch.material->shaderProperty.matrix4x4Property;
			for (auto i = m4p->begin(); i != m4p->end(); i++)
			{
				cmd->mat4Names.push_back(i->first);
				cmd->mat4Values.push_back(i->second);
			}
			auto textureProperty = &batch.material->shaderProperty.textureProperty;
			for (auto i = textureProperty->begin(); i != textureProperty->end(); i++)
			{
				auto id = i->first;
				auto tex = i->second;
				auto data = GraphicDataCenter::GetTextureCommandData(tex->Package());
				cmd->textureData.push_back(data);
			}

			back_DrawCommands.push_back(cmd);
		}

		void GraphicCommandManager::Clear(Color color, int mode)
		{
			auto cmd = new GClearCMD(color, mode);
			back_DrawCommands.push_back(cmd);
		}

		void GraphicCommandManager::SetWireframe(bool enable)
		{
			auto cmd = new GWireframeCMD(enable);
			back_setting.push_back(cmd);
		}
	}
}
