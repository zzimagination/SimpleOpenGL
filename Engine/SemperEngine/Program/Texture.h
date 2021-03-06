#ifndef __TEXTURE__
#define __TEXTURE__

#include <vector>
#include <string>
#include <memory>
#include "Common.h"
#include "ResourceConfig.h"
#include "TextureObject.h"

namespace Semper
{
	class Texture : public Core::IResourceTarget
	{
	public:

		enum class Filter
		{
			Nearest,

			Linear
		};

	private:

		Core::TextureObject* _object;

	public:

		Texture(int width, int height);

		Texture(Core::TextureObject* obj);

		~Texture();

		Texture* Copy();

		void SetColors(ArrayList<ColorByte> pixels);

		ArrayList<ColorByte> GetColors();

		void SetFilter(ResourceConfig::TextureFilter filter);

		ResourceConfig::TextureFilter GetFilter();

		// ͨ�� IResourceTarget �̳�
		virtual Core::ResourceObject* GetObject() override;
	};
}
#endif // !TEXTURE
