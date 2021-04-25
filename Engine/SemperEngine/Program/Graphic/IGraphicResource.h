#ifndef __IGRAPHICRESOURCE__
#define __IGRAPHICRESOURCE__

namespace Semper
{
	namespace Core
	{
		class IGraphicResource
		{
		public:

			virtual void CreateGraphicResource() = 0;

			virtual void DeleteGraphicResource() = 0;
		};
	}
}


#endif