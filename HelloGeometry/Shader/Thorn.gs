#version 330 core
layout (triangles) in;
layout (triangle_strip, max_vertices = 12) out;

in VS_OUT{
    vec2 texCoords;
} gs_in[];

//out vec3 fColor;
out vec2 TexCoords;
out vec3 normal;

uniform float time;
uniform float Speed;

vec3 GetNormal()
{
    vec3 a = vec3(gl_in[0].gl_Position) - vec3(gl_in[1].gl_Position);
    vec3 b = vec3(gl_in[2].gl_Position) - vec3(gl_in[1].gl_Position);
    return normalize(cross(a ,b));
}

void main() {
    normal = GetNormal();
  
    vec4 CentralPos = (gl_in[0].gl_Position + gl_in[1].gl_Position + gl_in[2].gl_Position) / 3;
    vec2 CenterTex = (gs_in[0].texCoords + gs_in[1].texCoords + gs_in[2].texCoords) / 3;

    CentralPos += vec4(normal, 0) * abs(sin(time)) * 5;

    for(int i = 0; i < 3; i++)
    {
        gl_Position = gl_in[i].gl_Position;
        TexCoords = gs_in[i].texCoords;
        EmitVertex();
        gl_Position = CentralPos;
        TexCoords = CenterTex;
        EmitVertex();
        int nexti = (i + 1) % 3;
        gl_Position = gl_in[nexti].gl_Position;
        TexCoords = gs_in[nexti].texCoords;
        EmitVertex();
    }
    
    gl_Position = gl_in[2].gl_Position;
    EmitVertex();
    gl_Position = gl_in[1].gl_Position;
    EmitVertex();
    gl_Position = gl_in[0].gl_Position;
    EmitVertex();
    EndPrimitive();

}