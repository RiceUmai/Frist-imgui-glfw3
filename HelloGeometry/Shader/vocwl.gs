#version 430 core
layout (triangles) in;
layout (triangle_strip, max_vertices = 24) out;

in VS_OUT{
    vec2 texCoords;
    vec3 normal;
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


void EmitQuad(vec4 p0, vec4 p1, vec4 p2, vec4 p3)
{
    vec3 V0 = p0.xyz - p1.xyz;
    vec3 V1 = p2.xyz - p1.xyz;

    normal = normalize(cross(V0, V1));

    gl_Position = p0;
    EmitVertex();
    gl_Position = p1;
    EmitVertex();
    gl_Position = p2;
    EmitVertex();
    gl_Position = p3;
    EmitVertex();
}


void main() {
    vec4 Center = (gl_in[0].gl_Position + gl_in[1].gl_Position + gl_in[2].gl_Position) / 3;

    vec4 P0;
    float voxel_size = 2.0f;
    P0.x = Center.x - voxel_size/2.0;;
    P0.y = Center.y - voxel_size/2.0;;
    P0.z = Center.z + voxel_size/2.0;;
    P0.w = 1.0f;

    vec4 P1;
    P1.x = Center.x - voxel_size/2.0;;
    P1.y = Center.y - voxel_size/2.0;;
    P1.z = Center.z + voxel_size/2.0;;
    P1.w = 1.0f;

    vec4 P2;
    P2.x = Center.x - voxel_size/2.0;;
    P2.y = Center.y - voxel_size/2.0;;
    P2.z = Center.z + voxel_size/2.0;;
    P2.w = 1.0f;

    vec4 P3;
    P3.x = Center.x - voxel_size/2.0;;
    P3.y = Center.y - voxel_size/2.0;;
    P3.z = Center.z + voxel_size/2.0;;
    P3.w = 1.0f;

    EmitQuad(P0, P1, P2, P3);
//===================================
//===================================
    P0.x = Center.x - voxel_size/2.0;;
    P0.y = Center.y - voxel_size/2.0;;
    P0.z = Center.z - voxel_size/2.0;;
    P0.w = 1.0f;

    P1.x = Center.x - voxel_size/2.0;;
    P1.y = Center.y + voxel_size/2.0;;
    P1.z = Center.z - voxel_size/2.0;;
    P1.w = 1.0f;

    P2.x = Center.x + voxel_size/2.0;;
    P2.y = Center.y - voxel_size/2.0;;
    P2.z = Center.z - voxel_size/2.0;;
    P2.w = 1.0f;

    P3.x = Center.x + voxel_size/2.0;;
    P3.y = Center.y + voxel_size/2.0;;
    P3.z = Center.z - voxel_size/2.0;;
    P3.w = 1.0f;

    EmitQuad(P0, P1, P2, P3);
    //===================================
//===================================
    P0.x = Center.x + voxel_size/2.0;;
    P0.y = Center.y - voxel_size/2.0;;
    P0.z = Center.z + voxel_size/2.0;;
    P0.w = 1.0f;

    P1.x = Center.x + voxel_size/2.0;;
    P1.y = Center.y + voxel_size/2.0;;
    P1.z = Center.z + voxel_size/2.0;;
    P1.w = 1.0f;

    P2.x = Center.x + voxel_size/2.0;;
    P2.y = Center.y - voxel_size/2.0;;
    P2.z = Center.z - voxel_size/2.0;;
    P2.w = 1.0f;

    P3.x = Center.x + voxel_size/2.0;;
    P3.y = Center.y + voxel_size/2.0;;
    P3.z = Center.z - voxel_size/2.0;;
    P3.w = 1.0f;

    EmitQuad(P0, P1, P2, P3);
    //===================================
//===================================
    P0.x = Center.x - voxel_size/2.0;;
    P0.y = Center.y - voxel_size/2.0;;
    P0.z = Center.z - voxel_size/2.0;;
    P0.w = 1.0f;

    P1.x = Center.x - voxel_size/2.0;;
    P1.y = Center.y + voxel_size/2.0;;
    P1.z = Center.z - voxel_size/2.0;;
    P1.w = 1.0f;

    P2.x = Center.x - voxel_size/2.0;;
    P2.y = Center.y - voxel_size/2.0;;
    P2.z = Center.z + voxel_size/2.0;;
    P2.w = 1.0f;

    P3.x = Center.x - voxel_size/2.0;;
    P3.y = Center.y + voxel_size/2.0;;
    P3.z = Center.z + voxel_size/2.0;;
    P3.w = 1.0f;

    EmitQuad(P0, P1, P2, P3);//===================================
//===================================
    P0.x = Center.x - voxel_size/2.0;;
    P0.y = Center.y + voxel_size/2.0;;
    P0.z = Center.z + voxel_size/2.0;;
    P0.w = 1.0f;

    P1.x = Center.x - voxel_size/2.0;;
    P1.y = Center.y + voxel_size/2.0;;
    P1.z = Center.z - voxel_size/2.0;;
    P1.w = 1.0f;

    P2.x = Center.x + voxel_size/2.0;;
    P2.y = Center.y + voxel_size/2.0;;
    P2.z = Center.z + voxel_size/2.0;;
    P2.w = 1.0f;

    P3.x = Center.x + voxel_size/2.0;;
    P3.y = Center.y + voxel_size/2.0;;
    P3.z = Center.z - voxel_size/2.0;;
    P3.w = 1.0f;

    EmitQuad(P0, P1, P2, P3);//===================================
//===================================
    P0.x = Center.x - voxel_size/2.0;;
    P0.y = Center.y - voxel_size/2.0;;
    P0.z = Center.z - voxel_size/2.0;;
    P0.w = 1.0f;

    P1.x = Center.x - voxel_size/2.0;;
    P1.y = Center.y - voxel_size/2.0;;
    P1.z = Center.z + voxel_size/2.0;;
    P1.w = 1.0f;

    P2.x = Center.x + voxel_size/2.0;;
    P2.y = Center.y - voxel_size/2.0;;
    P2.z = Center.z - voxel_size/2.0;;
    P2.w = 1.0f;

    P3.x = Center.x + voxel_size/2.0;;
    P3.y = Center.y - voxel_size/2.0;;
    P3.z = Center.z + voxel_size/2.0;;
    P3.w = 1.0f;

    EmitQuad(P0, P1, P2, P3);
    EndPrimitive();

}