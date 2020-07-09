#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;
layout (location = 2) in vec3 aNormal;
layout (location = 3) in vec3 aTangent;
layout (location = 4) in vec3 aBitangent;

// declare an interface block; see 'Advanced GLSL' for what these are.
out VS_OUT {
    vec3 FragPos;
    vec2 TexCoords;
	vec4 FragPosDirLightSpace;
	mat3 TBN;
} vs_out;


layout (std140) uniform Matrices
{
    mat4 projection;
    mat4 view;
};

layout (std140) uniform DirLightInfo
{
    vec3 dirDirection;
    vec3 dirAmbient;
    vec3 dirDiffuse;
    vec3 dirSpecular;
	mat4 dirLightSpaceMatrix;
};
uniform mat4 _model;
//uniform mat4 _dirLightSpaceMatrix;

void main()
{
	vec4 worldPos=_model * vec4(aPos, 1.0);
    vs_out.FragPos = worldPos.xyz;
    vs_out.TexCoords = aTexCoords;
	vs_out.FragPosDirLightSpace = dirLightSpaceMatrix * vec4(vs_out.FragPos, 1.0);

	mat3 normalMatrix = transpose(inverse(mat3(_model)));
    vec3 T = normalize(normalMatrix * aTangent);
    vec3 B = normalize(normalMatrix * aBitangent);
    vec3 N = normalize(normalMatrix * aNormal);    
	//mat3 TBN = transpose();  
    vs_out.TBN = mat3(T, B, N);

    gl_Position = projection * view *_model * vec4(aPos, 1.0);
}