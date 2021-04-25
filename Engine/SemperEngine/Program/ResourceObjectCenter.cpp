#include "ResourceObjectCenter.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

		std::vector<ResourceObject*> ResourceObjectCenter::_newObjects;

		std::vector<ResourceObject*> ResourceObjectCenter::_deleteObjects;

		std::vector<ResourceObject*> ResourceObjectCenter::_modifyObjects;

		void ResourceObjectCenter::EndProcess()
		{
			for (size_t i = 0; i < _newObjects.size(); i++)
			{
				_newObjects[i]->EndCreate();
			}
			_newObjects.clear();
			for (size_t i = 0; i < _modifyObjects.size(); i++)
			{
				_modifyObjects[i]->EndModify();
			}
			_modifyObjects.clear();
			for (size_t i = 0; i < _deleteObjects.size(); i++)
			{
				_deleteObjects[i]->EndDelete();
				delete _deleteObjects[i];
			}
			_deleteObjects.clear();
		}

		void ResourceObjectCenter::Create(ResourceObject* obj)
		{
			_newObjects.push_back(obj);
		}

		void ResourceObjectCenter::Delete(ResourceObject* obj)
		{
			_deleteObjects.push_back(obj);
		}

		void ResourceObjectCenter::Modify(ResourceObject* obj)
		{
			for (size_t i = 0; i < _modifyObjects.size(); i++)
			{
				if (_modifyObjects[i] == obj)
				{
					return;
				}
			}
			_modifyObjects.push_back(obj);
		}
	}
}