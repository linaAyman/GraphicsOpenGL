

#version 330 core

// Here we will define Uniform Variable
// they are called uniform because every run of the shader (under the same draw call) will see the same value
// so it is uniform across all executions of the shader
uniform vec3 color;
uniform float time;
uniform bool flicker;
uniform vec2 translation;
// The output that goes to the frame buffer
out vec4 frag_color;
in vec3 screenpos;


// Just a constant
#define PI 3.1415926535897932384626433832795

vec3 TRIANGLE(vec3 color, vec3 background, vec2 vertices[3], vec2 Pos);

void main()
{
    vec3 rightCircle=vec3(0.29,0.45,0.0);
    vec3 leftCircle=vec3(-0.29,0.45,0.0);
    vec3 UpperCircle=vec3(0.25,0.45,0.0);

    float distLeft  = length(screenpos-leftCircle);
    float distRight = length(screenpos-rightCircle);
    float distUpper = length(screenpos-UpperCircle);

    vec2 Pos = screenpos.xy;

    vec3 color = vec3(0.0);

    vec2 VERTS[3] = vec2[]
    (
    vec2(-0.59, 0.4),
    vec2(0.59, 0.4),
    vec2(0.0, -0.6)
    );

    color = TRIANGLE(vec3(1.0,0.0,0.0), color, VERTS, Pos);

    frag_color = vec4(color,1.0); //Red triangle
    if(distLeft < 0.3){
        frag_color = vec4(1.0, 0.0, 0.0, 1.0);  //left red circle
    }

    if(distRight < 0.3){
        frag_color = vec4(1.0, 0.0, 0.0, 1.0); //right red circle
    }

}

float TRIANGLE_sign(vec2 p1, vec2 p2, vec2 p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

vec3 TRIANGLE(vec3 color, vec3 background, vec2 vertices[3], vec2 Pos)
{
    bool b1 = TRIANGLE_sign(Pos, vertices[0], vertices[1]) < 0.0f; //3 line equations
    bool b2 = TRIANGLE_sign(Pos, vertices[1], vertices[2]) < 0.0f;
    bool b3 = TRIANGLE_sign(Pos, vertices[2], vertices[0]) < 0.0f;

    if((b1 == b2) && (b2 == b3))return color;
    return background;
}