#ifndef __GRAPHIC__
#define __GRAPHIC__

#include <map>
#include <string>
#include "IGraphicResource.h"
#include "../Collection/Collection.h"
#include "../Math/Math.h"

namespace Semper
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

		enum class TextureFilter
		{
			Nearest,

			Linear
		};
	};

#define ClearColorDepth (Graphic::ClearMode)((int)(Graphic::ClearMode::Color) |(int)(Graphic::ClearMode::Depth))

	namespace Core {

		struct RenderOperation
		{
			bool blend = false;

			Graphic::BlendFunc source = Graphic::BlendFunc::Zero;

			Graphic::BlendFunc destination = Graphic::BlendFunc::One;

			bool depth = true;

			Graphic::DepthFunc depthFunc = Graphic::DepthFunc::LEqual;

			bool cull = true;

			Graphic::CullFace cullFace = Graphic::CullFace::Back;

			static RenderOperation ScreenRender() {
				RenderOperation operation;
				operation.blend = true;
				operation.depth = false;
			}
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


		struct GraphicDataInfo
		{
			std::string name;

			int index = -1;
		};

		struct GraphicTextureInfo
		{
			std::string name;

			int index = -1;

			GraphicDataInfo info;
		};

		struct GraphicVertexInfo
		{
			std::string name;

			GraphicDataInfo info;
		};

		struct GraphicVertexResource
		{
			std::string name = "";

			ArrayList<Float3>* vertices = nullptr;

			ArrayList<Float2>* uv = nullptr;

			ArrayList<int>* index = nullptr;
		};

		struct GraphicTextureResource
		{
			std::string name = "";

			ArrayList<ColorByte>* pixels = nullptr;

			int width = -1;

			int height = -1;

			Graphic::TextureFilter filter = Graphic::TextureFilter::Nearest;
		};

		class ShaderProperty
		{
		public:

			int shaderID = 0;

			std::map<std::string, float> floatProperty;

			std::map<std::string, Float2> vector2Property;

			std::map<std::string, Float3> vector3Property;

			std::map<std::string, Float4> vector4Property;

			std::map<std::string, Color> colorProperty;

			std::map<std::string, Matrix4x4> matrix4x4Property;

			std::vector<GraphicDataInfo> textureProperty;

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

			void Add(std::string name, Color value)
			{
				colorProperty[name] = value;
			}

			void Add(std::string name, Matrix4x4 value)
			{
				matrix4x4Property[name] = value;
			}
		};
	}
}

#endif // !__GRAPHIC__
