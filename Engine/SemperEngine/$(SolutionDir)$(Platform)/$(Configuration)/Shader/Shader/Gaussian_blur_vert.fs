#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D image;

//uniform float weight[5] = float[] (0.2270270270, 0.1945945946, 0.1216216216, 0.0540540541, 0.0162162162);
//uniform float weight[5] = float[] (0.2270270270, 0.15, 0.10, 0.03, 0.01);

 //float offset[3] = float[]( 0.0, 1.3846153846, 3.2307692308 );
 float offset[3] = float[]( 0.0, 3.3846153846, 7.2307692308 );
 float weight[3] = float[](0.2270270270, 0.3162162162, 0.0702702703);

void main()
{             
     vec2 tex_offset = 1.0 / textureSize(image, 0); // gets size of single texel
     vec3 result = texture(image, TexCoords).rgb * weight[0];
         for(int i = 1; i < 3; ++i)
         {
            // result += texture(image, TexCoords + vec2(0.0, tex_offset.y * i)).rgb * weight[i];
            // result += texture(image, TexCoords - vec2(0.0, tex_offset.y * i)).rgb * weight[i];

			 result += texture2D( image, ( TexCoords+vec2(0.0, offset[i]*tex_offset.y) )).rgb * weight[i];
			 result	+= texture2D( image, ( TexCoords-vec2(0.0, offset[i]*tex_offset.y) )).rgb * weight[i];
         }
     FragColor = vec4(result, 1.0);
}