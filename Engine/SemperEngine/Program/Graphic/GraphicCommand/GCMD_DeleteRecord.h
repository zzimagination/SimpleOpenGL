#ifndef __CGMD_DELETERECORD__
#define __CGMD_DELETERECORD__

#include "../GraphicCommand.h"

namespace SemperEngine
{
	namespace Core
	{
		class GCMD_DeleteRecord : public GraphicCommand
		{
		public:

			GraphicRecord* record = nullptr;

			typedef void (*DeleteFunc)(GraphicRecord*);

			DeleteFunc deleteFunc = nullptr;

		public:

			GCMD_DeleteRecord(GraphicRecord* record, DeleteFunc func = nullptr);

			virtual ~GCMD_DeleteRecord() override;

			virtual void Excute() override;
		};
	}
}

#endif // !__CGMD_DELETERECORD__