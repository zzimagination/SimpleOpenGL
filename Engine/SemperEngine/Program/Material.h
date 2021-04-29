#ifndef __MATERIAL__
#define __MATERIAL__

#include <vector>
#include <map>
#include <string>
#include "Common.h"
#include "Graphic/Graphic.h"
#include "Texture.h"
#include "MaterialObject.h"
#include "Graphic/IGraphicResource.h"

namespace Semper
{
	class Material : public Core::IResourceTarget
	{
	public:

		enum class Depth
		{
			None,
			LEqual,
			GEqual,
			Always,
			Never,
		};

		enum class Cull
		{
			None,
			Back,
			Front,
		};

		enum class Source
		{
			Zero,
			One,
		};

		enum class Destination
		{
			Zero,
			One
		};

	private:

		Core::MaterialObject* _object;

	public:

		Material(std::string shader);

		~Material();

		void SetDepth(Depth mode);

		void SetBlend(bool enable, Source source = Source::Zero, Destination destination = Destination::One);

		void SetCull(Cull mode);

		void AddProperty(std::string name, float value);

		void AddProperty(std::string name, Float2 value);

		void AddProperty(std::string name, Float3 value);

		void AddProperty(std::string name, Float4 value);

		void AddProperty(std::string name, Matrix4x4 value);

		void AddProperty(std::string name, Color value);

		void AddProperty(std::string name, std::shared_ptr<Texture> value);

		void AddProperty(std::string name, std::shared_ptr<Texture> value, int order);

		// Í¨¹ý IResourceTarget ¼Ì³Ð
		virtual Core::ResourceObject* GetObject() override;

	};
}
#endif // !MATERIAL