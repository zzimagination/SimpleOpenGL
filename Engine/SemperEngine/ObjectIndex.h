#pragma once
#ifndef __OBJECT_INDEX__
#define __OBJECT_INDEX__

#include <memory>

namespace SemperEngine
{
	namespace Core
	{
		class ObjectIndex
		{
		private:

			std::shared_ptr<unsigned int> _id;

		public:

			ObjectIndex()
			{
				_id = std::shared_ptr<unsigned int>(new unsigned int(0));
			}

			~ObjectIndex(){}
			
			unsigned int ID()
			{
				if (*_id == 0)
				{
					throw "id is 0";
				}
				return *_id;
			}

			ObjectIndex& operator=(const ObjectIndex& right)
			{
				this->_id = right._id;
				return *this;
			}

			ObjectIndex& operator=(const unsigned int& right)
			{
				if (right <= 0)
				{
					throw "argument error";
				}
				*this->_id = right;
				return *this;
			}

			
		};
	}
}


#endif // !OBJECT_INDEX
