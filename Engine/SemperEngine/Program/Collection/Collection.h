#ifndef __COLLECTION__
#define __COLLECTION__

namespace Semper 
{
	template<class TK, class TV>
	struct Pair
	{
		TK key;

		TV value;

		Pair(TK k, TV v)
		{
			key = k;
			value = v;
		}
	};
}

#endif // !__COLLECTION__

#include "ArrayList.h"
#include "FillList.h"
#include "SequenceList.h"
