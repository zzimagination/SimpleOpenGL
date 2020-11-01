#include "RenderLayer.h"

namespace SemperEngine
{
	using namespace std;

	RenderLayer::RenderLayer()
	{
		_mode = Mode::all;
	}
	RenderLayer::~RenderLayer()
	{
	}
	void RenderLayer::Add(int layer)
	{
		if (layer == 0)
		{
			_mode = Mode::none;
			_layers.clear();
		}
		else if (layer == 1)
		{
			_mode = Mode::all;
			_layers.clear();
		}
		else
		{
			_mode = Mode::normal;
			if (!VectorContain(layer))
			{
				_layers.push_back(layer);
			}
		}
	}
	void RenderLayer::Remove(int layer)
	{
		if (layer == 0)
		{
			return;
		}
		else if (layer == 1)
		{
			_mode = Mode::none;
			_layers.clear();
		}
		else
		{
			VectorRemove(layer);
			if (_layers.size() == 0)
			{
				_mode = Mode::none;
			}
		}
	}
	bool RenderLayer::Contain(int layer)
	{
		if (_mode == Mode::none || layer == 0)
		{
			return false;
		}
		else if (_mode == Mode::all || layer == 1)
		{
			return true;
		}
		else
		{
			return	VectorContain(layer);
		}
	}
	bool RenderLayer::Contain(RenderLayer layer)
	{
		if (_mode == Mode::none || layer._mode == Mode::none)
		{
			return false;
		}
		else if (_mode == Mode::all || layer._mode == Mode::all)
		{
			return true;
		}
		else
		{
			for (size_t i = 0; i < layer._layers.size(); i++)
			{
				if (VectorContain(layer._layers[i]))
				{
					return true;
				}
			}
			return false;
		}
	}

	std::vector<int> RenderLayer::GetLayers()
	{
		vector<int> result;
		if (_mode == Mode::none)
		{
			result.push_back(0);
		}
		else if (_mode == Mode::all)
		{
			result.push_back(1);
		}
		else
		{
			result.assign(_layers.begin(),_layers.end());
		}
		return result;
	}

	bool RenderLayer::operator==(const int& layer)
	{
		return Contain(layer);
	}

	bool RenderLayer::operator==(const RenderLayer& layer)
	{
		return Contain(layer);
	}


	bool RenderLayer::VectorContain(int layer)
	{
		for (int i = 0; i < _layers.size(); i++)
		{
			if (_layers[i] == layer)
			{
				return true;
			}
		}
		return false;
	}
	void RenderLayer::VectorRemove(int layer)
	{
		for (int i = 0; i < _layers.size(); i++)
		{
			if (_layers[i] == layer)
			{
				_layers.erase(_layers.begin() + i);
				return;
			}
		}
	}
}