#pragma once
#ifndef __DATACENTER__
#define __DATACENTER__

#include <string>
#include <memory>
#include <vector>
#include "ResourcePackage.h"
#include "FillList.h"
#include "DataCenterClerk.h"

namespace SemperEngine
{
	namespace Core
	{
		class DataCenterBase
		{
		public:

			DataCenterBase();

			virtual ~DataCenterBase();

			virtual void Delete(int id) = 0;

		};

		template<class T>
		class DataCenter : public DataCenterBase
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

				~ResourceUnit();
			};

		public:

			FillList<ResourceUnit<T>> units;

		public:

			DataCenter();

			virtual ~DataCenter() override;

			ResourcePackage<T> CreatePackage();

			ResourcePackage<T> CreatePackage(T* data);

			ResourcePackage<T> CopyPackage(ResourcePackage<T> package);

			virtual void Delete(int id) override;

		private:

			std::shared_ptr<DataCenterClerk> CreateClerk();
		};

		template<class T>
		template<class TType>
		DataCenter<T>::ResourceUnit<TType>::ResourceUnit()
		{
		}

		template<class T>
		template<class TType>
		DataCenter<T>::ResourceUnit<TType>::~ResourceUnit()
		{
		}

		template<class T>
		DataCenter<T>::DataCenter()
		{
		}

		template<class T>
		DataCenter<T>::~DataCenter()
		{
		}

		template<class T>
		ResourcePackage<T> DataCenter<T>::CreatePackage()
		{
			auto clerk = CreateClerk();
			ResourcePackage<T> package(new T);
			package.clerk = clerk;
			ResourceUnit<T> unit;
			unit.package = package;
			clerk->id = units.Add(unit);
			return package;
		}

		template<class T>
		ResourcePackage<T> DataCenter<T>::CreatePackage(T* data)
		{
			auto clerk = CreateClerk();
			ResourcePackage<T> package(data);
			package.clerk = clerk;
			ResourceUnit<T> unit;
			unit.package = package;
			clerk->id = units.Add(unit);
			return package;
		}

		template<class T>
		ResourcePackage<T> DataCenter<T>::CopyPackage(ResourcePackage<T> package)
		{
			auto data = package.GetResource()->Copy();
			return CreatePackage(data);
		}

		template<class T>
		void DataCenter<T>::Delete(int id)
		{
			units.Remove(id);
		}

		template<class T>
		std::shared_ptr<DataCenterClerk> DataCenter<T>::CreateClerk()
		{
			auto clerk = std::shared_ptr<DataCenterClerk>(new DataCenterClerk());
			clerk->dataCenter = this;
			return clerk;
		}
	}
}

#endif // !__DATACENTER__
