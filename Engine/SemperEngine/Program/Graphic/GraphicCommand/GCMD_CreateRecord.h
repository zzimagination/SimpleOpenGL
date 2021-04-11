#ifndef __GCMD_CREATE_RECORD__
#define __GCMD_CREATE_RECORD__

#include "../GraphicCommand.h"

namespace SemperEngine
{
	namespace Core
	{
		class GCMD_CreateRecord : public GraphicCommand
		{
		public:

			GraphicRecord* record = nullptr;

		public:

			GCMD_CreateRecord(GraphicRecord* record);

			virtual ~GCMD_CreateRecord() override;

			virtual void Excute() override;
		};
	}
}
#endif // !__GCMD_CREATE_RECORD__
