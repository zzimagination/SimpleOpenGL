#define UNLITSECTION "Unlit"
#define DEPTHSECTION "Depth"

#ifndef __RENDER__
#define __RENDER__

namespace Semper
{
	class Render
	{
	public:
		enum class MSAA
		{
			None,
			Four,
			Eight,
			Sixteen,
		};
	};
}

#endif // !__RENDER__
