#ifndef __MATERIALOBJECT__
#define __MATERIALOBJECT__

#include <vector>
#include <map>
#include <list>
#include <memory>
#include "Collection/Collection.h"
#include "ResourceObject.h"
#include "Texture.h"
#include "Graphic/Graphic.h"


namespace Semper
{
	namespace Core
	{
		class MaterialObject : public ResourceObject, public IGraphicResource
		{
		public:

			static MaterialObject* Create(std::string shader);

		public:

			std::string shaderName = "";

			int shaderID = -1;

			bool blend = false;

			int source = 0;

			int destination = 0;

			int depth = 1;

			int cull = 0;

			std::map<std::string, float> floatProperties;

			std::map<std::string, Float2> float2Properties;

			std::map<std::string, Float3> float3Properties;

			std::map<std::string, Float4> float4Properties;

			std::map<std::string, Matrix4x4> matrix4x4Properties;

			std::map<std::string, std::shared_ptr<Texture>> textureProperties;

			SequenceList<std::string> textureList;

		public:

			virtual ~MaterialObject() override;

			MaterialObject* Copy();

		public:

			// Í¨¹ý IGraphicResource ¼Ì³Ð
			virtual void CreateGraphicResource() override;

			virtual void DeleteGraphicResource() override;
		};
	}
}

#endif // !__MATERIALOBJECT__
