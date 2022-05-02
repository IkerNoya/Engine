#ifndef RENDERER_H
#define RENDERER_H
#include "Division/Core.h"

namespace Division {

	enum class  RendererAPI {
		None = 0, OpenGL = 1,
	};

	class DIVISION_API Renderer {
		static RendererAPI _rendererAPI;

	public:
		static inline RendererAPI GetAPI() { return _rendererAPI; }
	};
}

#endif // !RENDERER_H

