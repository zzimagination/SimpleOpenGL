#pragma once
#ifndef __GRAPHIC__
#define __GRAPHIC__

#include <map>
#include <string>
#include "Common.h"

namespace SemperEngine
{
	namespace Core
	{
		class Graphic
		{
		public:
			enum class ClearMode
			{
				Color = 0b0001,
				Depth = 0b0010,
				Stencil = 0b0100
			};

			enum class DepthFunc
			{
				Never,
				Less,
				LEqual,
				Equal,
				GEqual,
				Greater,
				NotEqual,
				Always
			};

			enum class CullFace
			{
				Back,
				Front
			};

			enum class BlendFunc
			{
				One,
				Zero
			};
		};

#define ClearColorDepth (Graphic::ClearMode)((int)(Graphic::ClearMode::Color) |(int)(Graphic::ClearMode::Depth))

		struct RenderOperation
		{
			bool blend = false;

			Graphic::BlendFunc source = Graphic::BlendFunc::Zero;

			Graphic::BlendFunc destination = Graphic::BlendFunc::One;

			bool depth = true;

			Graphic::DepthFunc depthFunc = Graphic::DepthFunc::LEqual;

			bool cull = true;

			Graphic::CullFace cullFace = Graphic::CullFace::Back;
		};

		struct RenderMatrix
		{
			Matrix4x4 model;

			Matrix4x4 view;

			Matrix4x4 projection;
		};

		constexpr const char* MODEL_MATRIX = "_model";

		constexpr const char* VIEW_MATRIX = "_view";

		constexpr const char* PROJECTION_MARIX = "_projection";

		constexpr const char* MAINCOLOR = "_color";

		class ShaderProperty
		{
		public:

			std::string name = "Unlit";

			std::map<std::string, float> floatProperty;

			std::map<std::string, Float2> vector2Property;

			std::map<std::string, Float3> vector3Property;

			std::map<std::string, Float4> vector4Property;

			std::map<std::string, Matrix4x4> matrix4x4Property;

		public:

			ShaderProperty() {
			};

			~ShaderProperty() {
			};

			void Add(std::string name, float value)
			{
				floatProperty[name] = value;
			}

			void Add(std::string name, Float2 value)
			{
				vector2Property[name] = value;
			}

			void Add(std::string name, Float3 value)
			{
				vector3Property[name] = value;
			}

			void Add(std::string name, Float4 value)
			{
				vector4Property[name] = value;
			}

			void Add(std::string name, Matrix4x4 value)
			{
				matrix4x4Property[name] = value;
			}

			void Clear()
			{
				floatProperty.clear();
				vector2Property.clear();
				vector3Property.clear();
				vector4Property.clear();
				matrix4x4Property.clear();
				name = "Unlit";
			}
		};

		struct GraphicDataInfo
		{
			int index = -1;
		};

		struct GraphicTextureInfo
		{
			int index = -1;

			GraphicDataInfo info;
		};

		struct GraphicVertexInfo
		{
			GraphicDataInfo info;
		};
	}
}

#endif // !__GRAPHIC__
