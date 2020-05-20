#version 330 core
out vec4 FragColor;
in vec2 TexCoords;

uniform sampler2D _gPosition;
uniform sampler2D _gNormal;
uniform sampler2D _gAlbedoSpec;

uniform vec3 _viewPos;
uniform sampler2D _dirDepthMap;
uniform samplerCube _pointDepthMap;

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

struct SpotLight {
    vec3 position;
    vec3 direction;
    float cutOff;
    float outerCutOff;
  
    float constant;
    float linear;
    float quadratic;

    vec3 diffuse;
    vec3 specular;       
};
uniform SpotLight _spotLight;


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
    vec3 ambient  = dirAmbient  * color;
    vec3 diffuse  = dirDiffuse *  diff * color;
    vec3 specular = dirSpecular * spec*spStren;

    return diffuse + specular+ambient;
}

vec3 CalcPointLight(vec3 normal, vec3 fragPos, vec3 viewDir,vec3 color ,float shininess,float spStren)
{

	vec3 lightDir = normalize(pointPosition - fragPos);
    // 漫反射着色
    float diff = max(dot(normal, lightDir), 0.0);
    // 镜面光着色
	vec3 halfwayDir = normalize(lightDir + viewDir);  
    float spec = pow(max(dot(normal, halfwayDir), 0.0),shininess);
    // 衰减
    float distance    = length(pointPosition - fragPos);
    float attenuation = 1.0 / (1+pointConstant + pointLinear * distance + 
                 pointQuadratic * (distance * distance));    
    // 合并结果
    vec3 diffuse  = pointDiffuse  * diff * color;
    vec3 specular = pointSpecular * spec*spStren;
    diffuse  *= attenuation;
    specular *= attenuation;
	return diffuse + specular;
}

vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir,vec3 color ,float shininess,float spStren)
{
	vec3 lightDir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
	vec3 halfwayDir = normalize(lightDir + viewDir);  
    float spec = pow(max(dot(normal, halfwayDir), 0.0),shininess);
    // attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (1+light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    // spotlight intensity
    float theta = dot(lightDir, normalize(-light.direction)); 
    float epsilon = light.cutOff -light.outerCutOff;
    float intensity = clamp((theta -light.outerCutOff) / (epsilon+0.001), 0.0, 1.0);
    // combine results
    vec3 diffuse = light.diffuse * diff *color;
    vec3 specular = light.specular * spec*spStren;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;
    return diffuse + specular;
}

void main()
{         
    // 从G缓冲中获取数据
    vec3 FragPos = texture(_gPosition, TexCoords).rgb;
    vec3 Normal = texture(_gNormal, TexCoords).rgb;
    vec3 Albedo = texture(_gAlbedoSpec, TexCoords).rgb;
    // 然后和往常一样地计算光照
    vec3 viewDir = normalize(_viewPos - FragPos);
	vec3 result=vec3(0.0);
// 第一阶段：定向光照
	
	vec4 FragPosDirLightSpace=dirLightSpaceMatrix * vec4(FragPos, 1.0);
	float shadowValue=1-DirShadowCalculation(FragPosDirLightSpace,_dirDepthMap);
	result += CalcDirLight(Normal, viewDir,Albedo,128,1)*shadowValue+dirAmbient*Albedo;
// 第二阶段：点光源
	shadowValue=1-CubeMapShadowCalculation(FragPos,_pointDepthMap);
	result += CalcPointLight(Normal, FragPos, viewDir,Albedo,256,1)*shadowValue;  
// 第三阶段：聚光
    result += CalcSpotLight(_spotLight, Normal, FragPos, viewDir,Albedo,128,1);

	
	FragColor = vec4(result,1.0);

}  