#ifndef RENDERER_H
#define RENDERER_H

#include "Division/Core.h"
#include "Division/Layer/Layer.h"
namespace Division {

	class DIVISION_API RendererContext : public Layer{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
	};

}


#endif // !RENDERER_H

