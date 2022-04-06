#ifndef SHADER_H
#define SHADER_H

#include "Division/Core.h"

namespace Division 
{
	class DIVISION_API Shader
	{
		unsigned int _id;
		std::string _vertex;
		std::string _fragment;
	public:

		void LoadShader(const char* vertexPath, const char* fragmentPath);
		void LoadVertex(const char* vertexPath);
		void LoadFragment(const char* FragmentPath);
		void BuildShader();

		inline unsigned int GetID() { return _id; }
	};
}

#endif // !SHADER_H



