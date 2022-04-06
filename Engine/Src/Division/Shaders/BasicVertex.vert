#version 460
in vec3 aPosition;

uniform mat4 transform = mat4(1.0);

out vec4 vertexColor;

void main()
{
	gl_Position = transform * vec4(aPosition, 1.0);
	vertexColor = vec4(0.5, 0.0, 0.0, 1.0);
}