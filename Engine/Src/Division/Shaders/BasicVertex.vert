#version 460 core
layout(location = 0) in vec3 position;

uniform mat4 transform = mat4(1.0);

out vec4 vertexColor;

void main()
{
	gl_Position = transform * vec4(position, 1.0);
	vertexColor = vec4(0.5, 0.0, 0.0, 1.0);
}