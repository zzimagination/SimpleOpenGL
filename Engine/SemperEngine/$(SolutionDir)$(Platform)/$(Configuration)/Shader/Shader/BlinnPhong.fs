#version 330 core
 out vec4 FragColor;

in VS_OUT {
    vec3 FragPos;
    vec2 TexCoords;
	vec4 FragPosDirLightSpace;
	mat3 TBN;
} fs_in;

uniform vec3 _color;
uniform vec3 _viewPos;

uniform sampler2D _dirDepthMap;
uniform samplerCube _pointDepthMap;

struct Material {
    sampler2D diffuseTex;
	sampler2D normalTex;
	float shininess;
	float specularStrength;
}; 
uniform Material _material;

layout (std140) uniform DirLightInfo
{
    vec3 dirDirection;
    vec3 dirAmbient;
    vec3 dirDiffuse;
    vec3 dirSpecular;
	mat4 dirLightSpaceMatrix;
};

layout (std140) uniform PointLightInfo{
    vec3 pointPosition;
    vec3 pointDiffuse;
    vec3 pointSpecular;
    float pointConstant;
    float pointLinear;
    float pointQuadratic;
	float pointFar_plane;
};

layout (std140) uniform SpotLightInfo{
    vec3 spotPosition;
	vec3 spotDirection;
    vec3 spotDiffuse;
    vec3 spotSpecular;
	float spotCutOff;
	float spotOuterCutOff;
    float spotConstant;
    float spotLinear;
    float spotQuadratic;
};

float DirShadowCalculation(vec4 fragPosLightSpace,sampler2D depthMap)
{
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
	projCoords = projCoords * 0.5 + 0.5;   
	float currentDepth = projCoords.z;  
	float bias = 0.005f;  

	float shadow = 0.0;
    vec2 texelSize =1.0 / textureSize(depthMap, 0);
	int rate=1;
	float sample=2.0;
	float offset=3;
    for(float x = -offset; x < offset; x+=offset/(sample*0.5))
    {
        for(float y = -offset; y < offset; y+=offset/(sample*0.5))
        {
            float pcfDepth = texture(depthMap, projCoords.xy + vec2(x, y) * texelSize).r;       
			shadow= shadow+(1- step(currentDepth - bias,pcfDepth));
        }    
    }
    shadow /= sample*sample;
	shadow=step(projCoords.z,1)*shadow;
	return shadow;
}


float CubeMapShadowCalculation(vec3 fragPos,samplerCube depthMap)
{
    vec3 fragToLight = fragPos - pointPosition; 
	float currentDepth = length(fragToLight);  

	float shadow  = 0.0;
	float bias    = 0.05; 
	float samples = 4.0;
	float offset  = 0.1;

	for(float x = -offset; x < offset; x += offset / (samples * 0.5))
	{
		for(float y = -offset; y < offset; y += offset / (samples * 0.5))
		{
			for(float z = -offset; z < offset; z += offset / (samples * 0.5))
			{
				float closestDepth = texture(depthMap, fragToLight + vec3(x, y, z)).r; 
				closestDepth *=pointFar_plane;   // Undo mapping [0;1]
				
				shadow= shadow+(1- step(currentDepth - bias,closestDepth));
				//if(currentDepth - bias > closestDepth)
				//    shadow += 1.0;
			}
		}
	}
	shadow /= (samples * samples * samples);

	return shadow;
}

vec3 CalcDirLight(vec3 normal, vec3 viewDir,vec3 color,float shininess,float spStren)
{
	vec3 lightDir = normalize(-dirDirection);
    // 漫反射着色
    float diff = max(dot(normal, lightDir), 0.0);
    // 镜面光着色
	vec3 halfwayDir = normalize(lightDir + viewDir);  
    float spec = pow(max(dot(normal, halfwayDir), 0.0),shininess);

    // 合并结果
    vec3 diffuse  = dirDiffuse *  diff * color;
    vec3 specular = dirSpecular * spec*spStren;

    return diffuse + specular;
}

vec3 CalcPointLight(vec3 normal, vec3 fragPos, vec3 viewDir,vec3 color,float shininess,float spStren)
{

	vec3 lightDir = normalize(pointPosition - fragPos);
    // 漫反射着色
    float diff = max(dot(normal, lightDir), 0.0);
    // 镜面光着色
	vec3 halfwayDir = normalize(lightDir + viewDir);  
    float spec = pow(max(dot(normal, halfwayDir), 0.0),shininess);
    // 衰减
    float distance    = length(pointPosition - fragPos);
    float attenuation = 1.0 / (pointConstant + pointLinear* distance + 
                pointQuadratic* (distance * distance));    
    // 合并结果
    vec3 diffuse  = pointDiffuse * diff * color;
    vec3 specular = pointSpecular * spec*spStren;
    diffuse  *= attenuation;
    specular *= attenuation;
	return diffuse + specular;
}

vec3 CalcSpotLight( vec3 Normal, vec3 FragPos, vec3 viewDir,vec3 color,float shininess,float spStren)
{
    
    // diffuse 
    vec3 norm = Normal;
    vec3 lightDir = normalize(spotPosition - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = spotDiffuse * diff *color;  
    
    // specular
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0),shininess);
    vec3 specular = spotSpecular * spec;  
   


    // spotlight (soft edges)
	vec3 spotDir= normalize(spotDirection);
	float theta = dot(lightDir,  -spotDir); 
    float epsilon = (spotCutOff - spotOuterCutOff);
    float intensity = clamp((theta-spotOuterCutOff) /epsilon, 0.0, 1.0);
    diffuse  *= intensity;
    specular *= intensity;
 
    // attenuation
    float distance    = length(spotPosition - FragPos);
    float attenuation = 1.0 / (spotConstant + spotLinear * distance + spotQuadratic * (distance * distance));    
	
    diffuse  *= attenuation;
    specular *= attenuation;   
        
    return diffuse +specular;
}

void main()
{           

// 属性
	vec3 color = texture(_material.diffuseTex, fs_in.TexCoords).rgb;
	vec3 norm = texture(_material.normalTex, fs_in.TexCoords).rgb;
	norm = normalize(norm * 2.0 - 1.0);
	norm=normalize(fs_in.TBN * norm);

    vec3 viewDir = normalize(_viewPos - fs_in.FragPos);
	vec3 result=vec3(0.0);
// 第一阶段：定向光照
	float shadowValue=1-DirShadowCalculation(fs_in.FragPosDirLightSpace,_dirDepthMap);
   result += CalcDirLight(norm, viewDir,color,_material.shininess,_material.specularStrength)*shadowValue+dirAmbient*color;
// 第二阶段：点光源
	shadowValue=1-CubeMapShadowCalculation(fs_in.FragPos,_pointDepthMap);
	result += CalcPointLight( norm, fs_in.FragPos, viewDir,color,_material.shininess,_material.specularStrength)*shadowValue;  
// 第三阶段：聚光
    result += CalcSpotLight(norm, fs_in.FragPos, viewDir,color,_material.shininess,_material.specularStrength);

	FragColor = vec4(result*_color,1.0);
	//FragColor = vec4(norm,1.0);
}