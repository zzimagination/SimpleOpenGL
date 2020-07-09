#version 330 core
layout (location = 0) out vec4 FragColor;
layout (location = 1) out vec4 BrightColor;

in vec2 TexCoords;
uniform sampler2D _colorBuffer;

void main()
{
	vec3 col= texture(_colorBuffer, TexCoords).rgb;
    FragColor = vec4(col, 1.0);

	float brightness =dot(FragColor.rgb, vec3(0.2126, 0.7152, 0.0722));
	float t=step(2,brightness);
    BrightColor= vec4(FragColor.rgb*t, 1.0);
} 