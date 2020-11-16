#pragma once
#ifndef __DATACENTER__
#define __DATACENTER__

#include <string>
#include <memory>
#include <vector>
#include "ResourcePackage.h"
#include "Graphic.h"

namespace SemperEngine
{
	namespace Core
	{
		class DataCenter
		{
		protected:

			template<class TType>
			class ResourceUnit
			{
			public:
				ResourcePackage<TType> package;

				std::string path;

			public:

				ResourceUnit();

				virtual ~ResourceUnit();
			};

			template<class TType>
			class GPResourceUnit : public ResourceUnit<TType>
			{
			public:
				
				GraphicDataInfo graphicDataInfo;

			public:

				GPResourceUnit();

				virtual ~GPResourceUnit() override;
			};

		};
		template<class TType>
		inline DataCenter::ResourceUnit<TType>::ResourceUnit()
		{
		}
		template<class TType>
		inline DataCenter::ResourceUnit<TType>::~ResourceUnit()
		{
		}
		template<class TType>
		inline DataCenter::GPResourceUnit<TType>::GPResourceUnit()
		{
		}
		template<class TType>
		inline DataCenter::GPResourceUnit<TType>::~GPResourceUnit()
		{
		}
	}
}

#endif // !__DATACENTER__
