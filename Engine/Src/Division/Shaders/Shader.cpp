#include "dpch.h"
#include "Shader.h"
#include <fstream>
#include <sstream>
#include <glad/glad.h>

namespace Division 
{
	Shader::Shader(){
	}
	Shader::Shader(const char* vertexPath, const char* fragmentPath){
		LoadShader(vertexPath, fragmentPath);
	}
	Shader::~Shader(){
		glDeleteProgram(_id);
	}
	void Shader::LoadShader(const char* vertexPath, const char* fragmentPath){
		LoadVertex(vertexPath);
		LoadFragment(fragmentPath);
		BuildShader();
	}

	void Shader::LoadVertex(const char* vertexPath){

		std::ifstream vertexFile;
		std::stringstream vertexBuffer;

		vertexFile.open(vertexPath);
		if (vertexFile.is_open()) {
			vertexBuffer << vertexFile.rdbuf();
			vertexFile.close();
		}
		else {
			std::cout << "Couldn't open vertex file" << std::endl;
		}
		_vertexSrc = vertexBuffer.str();
	}


	void Shader::LoadFragment(const char* FragmentPath){
		std::ifstream fragmentFile;

		std::stringstream fragmentBuffer;

		fragmentFile.open(FragmentPath);
		if (fragmentFile.is_open()) {
			fragmentBuffer << fragmentFile.rdbuf();
			fragmentFile.close();
		}
		else {
			std::cout << "Couldn't open fragment file" << std::endl;
		}
		_fragmentSrc = fragmentBuffer.str();

	}

	unsigned int Shader::CompileShader(unsigned int type, std::string& source){
		// -----------Compile------------------
		unsigned int shaderID = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(shaderID, 1, &src, nullptr);
		glCompileShader(shaderID);

		int result;
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);

		if (result == GL_FALSE) {
			int length;
			glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)_malloca(length * sizeof(char));
			glGetShaderInfoLog(shaderID, length, &length, message);

			DIV_CORE_ERROR("Shader compilation failed!");
			DIV_CORE_ERROR("{0}", message);
			std::cout << message << std::endl;
			glDeleteShader(shaderID);
			return 0;
		}
		return shaderID;

	}

	void Shader::BuildShader(){
		_id = glCreateProgram();
		unsigned int vertexID = CompileShader(GL_VERTEX_SHADER, _vertexSrc);
		unsigned int fragmentID = CompileShader(GL_FRAGMENT_SHADER, _fragmentSrc);
		glAttachShader(_id, vertexID);
		glAttachShader(_id, fragmentID);

		glLinkProgram(_id);
		glValidateProgram(_id);

		glDeleteShader(vertexID);
		glDeleteShader(fragmentID);
	}
	void Shader::Bind() const{
		glUseProgram(_id);
	}
	void Shader::Unbind() const{
		glUseProgram(0);
	}
}