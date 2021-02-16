#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

//out vec2 TexCoords;

out VS_OUT{
    vec2 texCoords;
    vec3 normal;
} vs_out;

out vec3 normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform float time;

void main()
{
    //TexCoords = aTexCoords;
    vs_out.texCoords = aTexCoords;
    vs_out.normal = aNormal;
    normal = aNormal;

    vec3 test = aPos;
    test.y += sin(test.x * time);
    
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}