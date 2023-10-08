#version 330 core
layout(location = 0) in vec3 in_Position;
layout(location = 1) in vec3 in_Color;

uniform mat4 transform;



out vec3 out_Color;



void main()
{
	gl_Position = transform * vec4(in_Position,1.0);

	out_Color = in_Color;
}