#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;
layout (location = 2) in vec3 aNormal;
layout (location = 3) in vec3 aTangent;
layout (location = 4) in vec3 aBitangent;

out VS_OUT {
    vec3 FragPos;
    vec2 TexCoords;
	mat3 TBN;
} vs_out;


uniform mat4 _model;

layout (std140) uniform Matrices
{
    mat4 projection;
    mat4 view;
};


void main()
{
    vec4 worldPos = _model * vec4(aPos, 1.0);
    vs_out.FragPos = worldPos.xyz; 
    vs_out.TexCoords = aTexCoords;
    
    mat3 normalMatrix = transpose(inverse(mat3(_model)));

    vec3 T = normalize(normalMatrix * aTangent);
    vec3 B = normalize(normalMatrix * aBitangent);
    vec3 N = normalize(normalMatrix * aNormal);   
	vs_out.TBN=mat3(T,B,N);

    gl_Position = projection * view * worldPos;


}