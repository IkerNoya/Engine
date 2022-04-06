#include "dpch.h"
#include "Shader.h"

namespace Division 
{
	void Shader::LoadShader(const char* vertexPath, const char* fragmentPath){
		LoadVertex(vertexPath);
		LoadFragment(fragmentPath);
		BuildShader();
	}

	void Shader::LoadVertex(const char* vertexPath){
	}

	void Shader::LoadFragment(const char* FragmentPath){
	}

	void Shader::BuildShader(){
	}
}