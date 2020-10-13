#pragma once
#ifndef __GRAPHICCOMMAND__
#define __GRAPHICCOMMAND__

#include <vector>
#include <map>
#include <memory>
#include "Mathz.h"
#include "ShaderProperty.h"
#include "ResourcePackage.h"
#include "VertexData.h"
#include "GraphicVertexData.h"
#include "Texture.h"
#include "GraphicTextureData.h"

namespace SemperEngine
{
	namespace Core
	{
		template<class DATA, class GDATA>
		class GraphicCommandData
		{
		public:

			ResourcePackage<DATA> package;

			GDATA graphicData;

		public:

			GraphicCommandData() {}
			~GraphicCommandData() {}
		};

		typedef GraphicCommandData<VertexData, GraphicVertexData> VertexCommandData;

		typedef GraphicCommandData<Texture, GraphicTextureData> TextureCommandData;

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

			std::shared_ptr<VertexCommandData> data;

		public:

			GVertexBufferCMD(std::shared_ptr<VertexCommandData> data);

			virtual ~GVertexBufferCMD() override;

			virtual void Excute() override;
		};

		class GVertexBufferClearCMD : public GraphicCommand
		{
		public:

			std::shared_ptr<VertexCommandData> data;

		public:

			GVertexBufferClearCMD(std::shared_ptr<VertexCommandData> data);

			virtual ~GVertexBufferClearCMD() override;

			virtual void Excute() override;
		};

		class GDrawCMD : public GraphicCommand
		{
		public:

			std::weak_ptr<VertexCommandData> vertexData;

			Matrix4x4 modelMatrix;

			Matrix4x4 viewMatrix;

			Matrix4x4 projectionMatrix;

			std::string shader;

			ShaderProperty shaderProperty;

		public:

			GDrawCMD(std::shared_ptr<VertexCommandData> v, Matrix4x4 m, Matrix4x4 view, Matrix4x4 p, std::string shader, ShaderProperty& pro);

			virtual ~GDrawCMD() override;

			virtual void Excute() override;
		};

		class GClearCMD : public GraphicCommand
		{
		public:

			Color color;

			int mode;

		public:

			GClearCMD(Color color, int mode);

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