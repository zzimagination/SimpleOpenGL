#pragma once
#ifndef __GRAPHICCOMMAND__
#define __GRAPHICCOMMAND__

#include <vector>
#include <map>
#include <memory>
#include "Graphic.h"
#include "GraphicResource.h"
#include "Graphic/GraphicRecord.h"

namespace SemperEngine
{
	namespace Core
	{		
		class GraphicCommand
		{
		public:

			GraphicCommand() {};

			virtual ~GraphicCommand() {};

			virtual void Excute() = 0;

			void SetShaderProperty(ShaderProperty p);
		};

		class GVertexBufferCMD : public GraphicCommand
		{
		public:

			GraphicDataInfo dataInfo;

		public:

			GVertexBufferCMD(GraphicDataInfo info);

			virtual ~GVertexBufferCMD() override;

			virtual void Excute() override;
		};

		class GVertexBufferClearCMD : public GraphicCommand
		{
		public:

			GraphicDataInfo dataInfo;

		public:

			GVertexBufferClearCMD(GraphicDataInfo info);

			virtual ~GVertexBufferClearCMD() override;

			virtual void Excute() override;
		};

		class GTextureBufferCMD :public GraphicCommand
		{
		public:

			GraphicDataInfo dataInfo;

		public:

			GTextureBufferCMD(GraphicDataInfo info);

			virtual ~GTextureBufferCMD() override;

			virtual void Excute() override;
		};

		class GTextureBufferClearCMD : public GraphicCommand
		{
		public:

			GraphicDataInfo dataInfo;

		public:

			GTextureBufferClearCMD(GraphicDataInfo info);

			virtual ~GTextureBufferClearCMD() override;

			virtual void Excute() override;
		};

		class GDrawCMD : public GraphicCommand
		{
		public:

			RenderOperation operation;

			GraphicVertexInfo vertex;

			ShaderProperty shaderProperty;

			std::vector<GraphicTextureInfo> textures;

			bool useRecord = false;

		public:

			GDrawCMD();

			virtual ~GDrawCMD() override;

			virtual void Excute() override;

		private:

			void SetShaderProperty(ShaderProperty shaderP);
		};



		class GClearCMD : public GraphicCommand
		{
		public:

			Color color;

			Graphic::ClearMode mode;

		public:

			GClearCMD(Color color, Graphic::ClearMode mode);

			virtual ~GClearCMD() override;

			virtual void Excute() override;
		};

		class GWireframeCMD : public GraphicCommand
		{
		public:

			bool enable;

		public:

			GWireframeCMD(bool enable);

			virtual ~GWireframeCMD() override;

			virtual void Excute() override;
		};

		class GCMD_CreateRecord : public GraphicCommand
		{
		public:

			GraphicRecord* record = nullptr;

			std::string name;

		public:

			GCMD_CreateRecord();

			virtual ~GCMD_CreateRecord() override;

			virtual void Excute() override;
		};

		class GCMD_StopRecord : public GraphicCommand
		{
		public:

			GraphicRecord* record = nullptr;

		public:

			GCMD_StopRecord();

			virtual ~GCMD_StopRecord() override;

			virtual void Excute() override;
		};

		class GCMD_ClearRecords : public GraphicCommand
		{
		public:
			virtual ~GCMD_ClearRecords() override;

			virtual void Excute() override;
		};

		class GCMD_DrawRecord : public GraphicCommand
		{
		public:

			GraphicVertexInfo vertex;

			RenderOperation operation;

			ShaderProperty shaderProperty;

		public:

			virtual ~GCMD_DrawRecord() override;

			// Í¨¹ý GraphicCommand ¼Ì³Ð
			virtual void Excute() override;
		};
	}
}

#endif