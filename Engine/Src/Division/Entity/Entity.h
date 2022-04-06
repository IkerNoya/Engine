#ifndef ENTITY_H
#define ENTITY_H

#include "Division/Layer/Layer.h"
#include "Division/Core.h"

namespace Division 
{
	struct DIVISION_API Transform {
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
	};
	class DIVISION_API Entity : public Layer{
		

	public:
		Transform transform;


	};
}

#endif // !ENTITY_H





