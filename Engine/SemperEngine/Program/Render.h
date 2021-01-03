#pragma once
#ifndef __RENDER__
#define __RENDER__

#include "Mathz.h"

namespace SemperEngine
{
	namespace Core 
	{
		class RenderEnum
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

#define ClearColorDepth (RenderEnum::ClearMode)((int)(RenderEnum::ClearMode::Color) |(int)(RenderEnum::ClearMode::Depth))

		struct RenderOperation
		{
			bool blend = false;

			RenderEnum::BlendFunc source = RenderEnum::BlendFunc::Zero;

			RenderEnum::BlendFunc destination = RenderEnum::BlendFunc::One;

			bool depth = true;

			RenderEnum::DepthFunc depthFunc = RenderEnum::DepthFunc::LEqual;

			bool cull = true;

			RenderEnum::CullFace cullFace = RenderEnum::CullFace::Back;
		};

		struct RenderMatrix
		{
			Matrix4x4 model;

			Matrix4x4 view;

			Matrix4x4 projection;
		};
	}
}

#endif // !__RENDER__
