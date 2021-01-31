#pragma once
#ifndef __GRAPHICCOMMAND__
#define __GRAPHICCOMMAND__

#include <vector>
#include <map>
#include <memory>
#include "Graphic.h"
#include "GraphicResource.h"

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

			RenderMatrix matrix;

			ShaderProperty shaderProperty;

			std::vector<GraphicTextureInfo> textures;

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
	}
}

#endif