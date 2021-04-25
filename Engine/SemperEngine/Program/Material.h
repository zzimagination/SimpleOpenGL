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
	private:

		Core::MaterialObject* _object;

	public:

		Material();

		~Material();

		Material(std::string shader);

		void Blend(bool enable, Graphic::BlendFunc src = Graphic::BlendFunc::Zero, Graphic::BlendFunc dest = Graphic::BlendFunc::One);

		void CullFace(bool enable, Graphic::CullFace face = Graphic::CullFace::Back);

		void Depth(bool enable, Graphic::DepthFunc func = Graphic::DepthFunc::Always);

		std::vector<std::shared_ptr<Texture>> GetTextures();

		void AddProperty(std::string name, float value);

		void AddProperty(std::string name, Float2 value);

		void AddProperty(std::string name, Float3 value);

		void AddProperty(std::string name, Float4 value);

		void AddProperty(std::string name, Matrix4x4 value);

		void AddProperty(std::string name, Color value);

		void AddProperty(int id, std::shared_ptr<Texture> value);



		// Í¨¹ý IResourceTarget ¼Ì³Ð
		virtual Core::ResourceObject* GetObject() override;

	};
}
#endif // !MATERIAL