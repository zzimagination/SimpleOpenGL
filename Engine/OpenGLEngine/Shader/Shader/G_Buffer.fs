#version 330 core
layout (location = 0) out vec3 gPosition;
layout (location = 1) out vec3 gNormal;
layout (location = 2) out vec4 gAlbedoSpec;

in VS_OUT {
    vec3 FragPos;
    vec2 TexCoords;
	mat3 TBN;
} fs_in;

uniform sampler2D _texture_diffuse1;
uniform sampler2D _texture_normal1;

void main()
{    

    gPosition = fs_in.FragPos;
	vec3 texNormal= texture(_texture_normal1, fs_in.TexCoords).rgb;
	texNormal=(texNormal*2-1);
	texNormal=normalize(fs_in.TBN*texNormal);
	gNormal= texNormal;

	gAlbedoSpec.rgb = texture(_texture_diffuse1, fs_in.TexCoords).rgb;
}