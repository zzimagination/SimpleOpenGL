#version 330 core
layout (location = 0) out vec4 FragColor;

in vec2 TexCoords;

uniform vec3 _color;
uniform sampler2D _mainTex;

void main()
{             
    vec3 col = texture(_mainTex, TexCoords).rgb*_color;
	FragColor=vec4(col,1.0);
}