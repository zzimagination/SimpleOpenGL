#version 330 core
in vec4 FragPos;
out vec4 FragColor;

uniform vec3 _lightPos;
uniform float _far_plane;

void main()
{
    // get distance between fragment and light source
    float lightDistance = length(FragPos.xyz - _lightPos);
    
    // map to [0;1] range by dividing by far_plane
    lightDistance = lightDistance / _far_plane;
    
    // write this as modified depth
    gl_FragDepth = lightDistance;
}  