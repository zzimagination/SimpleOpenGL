#version 330 core
layout (location = 0) out vec4 FragColor;

in vec2 TexCoords;
uniform sampler2D _mainTex;

void main()
{
	vec3 color=texture(_mainTex,TexCoords).rgb;
    FragColor = vec4(color, 1.0);
} 