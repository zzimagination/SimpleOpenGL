#pragma once
#ifndef __GRAPHICCOMMAND__
#define __GRAPHICCOMMAND__

#include <vector>
#include <map>
#include <memory>
#include "Mathz.h"
#include "ShaderProperty.h"
#include "VertexDataCenter.h"
#include "VertexData.h"
#include "TextureData.h"
#include "GraphicResource.h"

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

		typedef std::shared_ptr<GraphicCommandData<VertexData, GraphicVertexData>> VertexCommandData;
#define VertexCommandDataInstance std::shared_ptr<GraphicCommandData<VertexData, GraphicVertexData>>(new GraphicCommandData<VertexData, GraphicVertexData>())

		typedef std::shared_ptr<GraphicCommandData<TextureData, GraphicTextureData>> TextureCommandData;
#define TextureCommandDataInstance std::shared_ptr<GraphicCommandData<TextureData, GraphicTextureData>>(new GraphicCommandData<TextureData, GraphicTextureData>())

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

			VertexCommandData data;

		public:

			GVertexBufferCMD(VertexCommandData data);

			virtual ~GVertexBufferCMD() override;

			virtual void Excute() override;
		};

		class GVertexBufferClearCMD : public GraphicCommand
		{
		public:

			VertexCommandData data;

		public:

			GVertexBufferClearCMD(VertexCommandData data);

			virtual ~GVertexBufferClearCMD() override;

			virtual void Excute() override;
		};

		class GTextureBufferCMD :public GraphicCommand
		{
		public:

			TextureCommandData data;

		public:

			GTextureBufferCMD(TextureCommandData data);

			virtual ~GTextureBufferCMD() override;

			virtual void Excute() override;
		};

		class GTextureBufferClearCMD : public GraphicCommand
		{
		public:

			TextureCommandData data;

		public:

			GTextureBufferClearCMD(TextureCommandData data);

			virtual ~GTextureBufferClearCMD() override;

			virtual void Excute() override;
		};

		class GDrawCMD : public GraphicCommand
		{
		public:

			VertexCommandData vertexData;

			Matrix4x4 modelMatrix;

			Matrix4x4 viewMatrix;

			Matrix4x4 projectionMatrix;

			std::string shader;

			std::vector<std::string> floatNames;

			std::vector<float> floatValues;

			std::vector < std::string> vec2Names;

			std::vector<Vector2> vec2Values;

			std::vector<std::string> vec3Names;

			std::vector<Vector3> vec3Values;

			std::vector<std::string> vec4Names;

			std::vector<Vector4> vec4Values;

			std::vector<std::string> mat4Names;

			std::vector<Matrix4x4> mat4Values;

			std::vector<TextureCommandData> textureData;

		public:

			GDrawCMD();

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