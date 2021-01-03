#pragma once
#ifndef __RENDERLAYER__
#define __RENDERLAYER__

#include <vector>

namespace SemperEngine
{
	class RenderLayer
	{
	private:

		enum class Mode
		{
			normal,
			none,
			all
		};

	private:

		Mode _mode;

		std::vector<int> _layers;

	public:

		RenderLayer();

		~RenderLayer();

		void Add(int layer);

		void Remove(int layer);

		bool Contain(int layer);

		bool Contain(RenderLayer layer);

		std::vector<int> GetLayers();

		bool operator==(const int& layer);

		bool operator==(const RenderLayer& layer);

	private:

		bool VectorContain(int layer);

		void VectorRemove(int layer);
	};
}

#endif // !__RENDERLAYER__
