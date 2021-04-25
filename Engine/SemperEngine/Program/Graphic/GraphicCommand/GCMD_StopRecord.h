#ifndef __GCMD_STOP_RECORD__
#define __GCMD_STOP_RECORD__

#include "../GraphicCommand.h"

namespace Semper
{
	namespace Core
	{
		class GCMD_StopRecord : public GraphicCommand
		{
		public:

			GraphicRecord* record = nullptr;

		public:

			GCMD_StopRecord(GraphicRecord* record);

			virtual ~GCMD_StopRecord() override;

			virtual void Excute() override;
		};
	}
}
#endif // !__GCMD_STOP_RECORD__
