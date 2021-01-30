#version 330 core
layout (triangles) in;
layout (line_strip, max_vertices = 6) out;

in VS_OUT{
    vec2 texCoords;
    vec3 normal;
} gs_in[];

out vec2 TexCoords;
out vec3 normal;

uniform float time;
uniform float normal_length;

vec3 GetNormal()
{
    vec3 a = vec3(gl_in[0].gl_Position) - vec3(gl_in[1].gl_Position);
    vec3 b = vec3(gl_in[2].gl_Position) - vec3(gl_in[1].gl_Position);
    return normalize(cross(a ,b));
}


void main()
{
    normal = GetNormal();

    for(int i = 0; i < gl_in.length(); i++)
    {
        vec4 p = gl_in[i].gl_Position;
        vec3 N = GetNormal();

        gl_Position = p;
        EmitVertex();


        gl_Position = p + vec4(N * normal_length , 1.0f);
        EmitVertex();

        EndPrimitive();

    }
}