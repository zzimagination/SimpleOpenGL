#ifndef __GCMD_STARTRECORD__
#define __GCMD_STARTRECORD__

#include "../GraphicCommand.h"

namespace Semper
{
	namespace Core
	{
		class GCMD_StartRecord : public GraphicCommand
		{
		public:

			GraphicRecord* record = nullptr;

		public:

			GCMD_StartRecord(GraphicRecord* record);

			virtual ~GCMD_StartRecord() override;

			// ͨ�� GraphicCommand �̳�
			virtual void Execute() override;

		};
	}
}

#endif // !__GCMD_STARTRECORD__
