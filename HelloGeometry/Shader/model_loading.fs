
#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 normal;

uniform sampler2D texture_diffuse1;
uniform vec3 Color;

void main()
{    
    //FragColor = texture(texture_diffuse1, TexCoords);
    //FragColor = vec4(1, 1, 1, 1);
    //FragColor = vec4(Color, 1);
    FragColor = vec4(normal, 1);
}