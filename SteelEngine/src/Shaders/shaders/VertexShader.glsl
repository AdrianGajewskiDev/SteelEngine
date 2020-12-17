#version 330 core
				
layout(location = 0) in vec4 position;
uniform vec3 m_Color = vec3(1.0, 1.0, 1.0);
out vec3 vertexColor;

void main()
{
	gl_Position = position;
	vertexColor = m_Color;
};