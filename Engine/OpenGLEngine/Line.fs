#version 330 core
 out vec4 FragColor;

in vec2 TexCoords;
uniform vec3 color;

int main()
{
	//vec3 col=color;
    FragColor = vec4(1,1,1, 1.0);
} 