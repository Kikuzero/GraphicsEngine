#shader vertex
#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 textureCoordinates;

uniform mat4 u_MVP;

out vec2 TexCoord;

void main()
{
   gl_Position = u_MVP * vec4(vertexPosition_modelspace, 1);
   TexCoord = textureCoordinates;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 TexCoord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
	color = texture(u_Texture, TexCoord);
	//color = vec4(1);
	// = texCol;
};