#pragma once
#ifndef __RESOURCEOBJECT_CONTAINER__
#define __RESOURCEOBJECT_CONTAINER__

#include <string>
#include <vector>
#include <memory>
#include <type_traits>
#include "TextureObject.h"
#include "MeshObject.h"
#include "FillList.h"

namespace SemperEngine
{
	namespace Core
	{
		template<class T, class TSetting>
		class ResourceObjectContainer
		{
		protected:

			std::vector<std::shared_ptr<T>> _newObjects;

			std::vector<std::shared_ptr<T>> _deleteObjects;

			FillList<std::shared_ptr<T>> _objects;

			TSetting _setting;

		public:

			ResourceObjectContainer() {}

			virtual ~ResourceObjectContainer() {}

			void DeleteObjects()
			{
				for (int i = 0; i < _deleteObjects.size(); i++)
				{
					EndDelete(_deleteObjects[i]);
				}
				_deleteObjects.clear();
			}

			void NewObjects()
			{
				for (int i = 0; i < _newObjects.size(); i++)
				{
					EndCreate(_newObjects[i]);
				}
				_newObjects.clear();
			}

			virtual std::shared_ptr<T> Create() = 0;

			virtual std::shared_ptr<T> Load(std::string file)
			{
				return std::shared_ptr<T>();
			}

			virtual std::shared_ptr<T> LoadSave(std::string file)
			{
				return std::shared_ptr<T>();
			}

			virtual std::shared_ptr<T> Find(std::string file)
			{
				return std::shared_ptr<T>();
			}

			virtual std::shared_ptr<T> Copy(std::shared_ptr<T> resourceObject)
			{
				return std::shared_ptr<T>();
			}

			virtual void Delete(std::shared_ptr<T> obj) = 0;

			void Setting(TSetting setting)
			{
				_setting = setting;
			}

			void ResetSetting()
			{
				_setting = TSetting();
			}

		protected:

			virtual void EndDelete(std::shared_ptr<T> obj) = 0;

			virtual void EndCreate(std::shared_ptr<T> obj) = 0;

			void AddObject(std::shared_ptr<T> obj)
			{
				static_assert(std::is_base_of<ResourceObject, T>(), "type error");
				obj->id = _objects.Add(obj);
			}

			void RemoveObject(int id)
			{
				_objects.Remove(id);
			}

			std::shared_ptr<T> GetObject(std::string path)
			{
				for (int i = 0; i < _objects.Size(); i++)
				{
					if (_objects[i].usable && _objects[i].value->filePath == path)
					{
						return _objects[i].value;
					}
				}
				return std::shared_ptr<T>();
			}
		};

		class TextureObjectContainer : public ResourceObjectContainer<TextureObject, TextureObject::Setting>
		{
		public:

			TextureObjectContainer() {};

			virtual ~TextureObjectContainer() override {};

			virtual std::shared_ptr<TextureObject> Create() override;

			virtual std::shared_ptr<TextureObject> Load(std::string file) override;

			virtual std::shared_ptr<TextureObject> LoadSave(std::string file) override;

			virtual std::shared_ptr<TextureObject> Find(std::string file) override;

			virtual void Delete(std::shared_ptr<TextureObject> obj) override;

			virtual std::shared_ptr<TextureObject> Copy(std::shared_ptr<TextureObject> resourceObject) override;

		protected:

			virtual void EndDelete(std::shared_ptr<TextureObject> obj) override;

			virtual void EndCreate(std::shared_ptr<TextureObject> obj) override;
		};

		class MeshObjectContainer : public ResourceObjectContainer<MeshObject, MeshObject::Setting>
		{
		public:

			MeshObjectContainer() {};

			virtual ~MeshObjectContainer() override {};

			virtual std::shared_ptr<MeshObject> Create() override;

			std::shared_ptr<MeshObject> CreateCube();

			virtual void Delete(std::shared_ptr<MeshObject> obj) override;

			virtual std::shared_ptr<MeshObject> Copy(std::shared_ptr<MeshObject> resourceObject) override;

		protected:

			virtual void EndDelete(std::shared_ptr<MeshObject> obj) override;

			virtual void EndCreate(std::shared_ptr<MeshObject> obj) override;
		};
	}
}

#endif // !__RESOURCEOBJECT_CONTAINER__
