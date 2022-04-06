#pragma once
#ifndef SHAPE_H
#define SHAPE_H

#include "Division/Core.h"
#include "Division/Entity/Entity.h"
namespace Division {
	class DIVISION_API Shape : public Entity
	{
		float vertices[3 * 3]{
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f, 0.5f, 0.0f
		};
		unsigned int indices[3]{
			0,1,2
		};
		unsigned int _vbo = 0;
		unsigned int _vao = 0;
		unsigned int _ebo = 0;

	public:



		inline unsigned int GetVBO() { return _vbo; }
		inline unsigned int GetVAO() { return _vao; }
		inline unsigned int GetEBO() { return _ebo; }
	};

}



#endif // !SHAPE_H


