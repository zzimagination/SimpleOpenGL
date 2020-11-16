#pragma once
#ifndef __BASEDATA__
#define __BASEDATA__

namespace SemperEngine
{
	namespace Core
	{
		class BaseData
		{
		public:

			bool isReadOnly = false;

		public:

			BaseData() {};

			virtual ~BaseData() {};
		};
	}
}

#endif // !__BASEDATA__
