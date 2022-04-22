#ifndef SHADER_H
#define SHADER_H

#include "Division/Core.h"

namespace Division 
{
	class DIVISION_API Shader
	{
		unsigned int _id;
		std::string _vertexSrc;
		std::string _fragmentSrc;
		
	
		void LoadVertex(const char* vertexPath);
		void LoadFragment(const char* FragmentPath);
		unsigned int  CompileShader(unsigned int type, std::string& source);
	public:
		Shader();
		Shader(const char* vertexPath, const char* fragmentPath);
		~Shader();

		void LoadShader(const char* vertexPath, const char* fragmentPath);
		void BuildShader();
		void Bind() const;
		void Unbind() const;

		inline unsigned int GetID() { return _id; }
	};
}

#endif // !SHADER_H



