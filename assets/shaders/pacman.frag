#version 330 core

// Here we will define Uniform Variable
// they are called uniform because every run of the shader (under the same draw call) will see the same value
// so it is uniform across all executions of the shader
//uniform vec3 color;
//uniform float time;
//uniform bool flicker;
in vec3 screenpos;
//// The output that goes to the frame buffer
out vec4 frag_color;
//in vec3 trii;
//
//// Just a constant
//#define PI 3.1415926535897932384626433832795

//void main() {

float TRIANGLE_sign(vec2 p1, vec2 p2, vec2 p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

vec3 TRIANGLE(vec3 color, vec2 vertices[3], vec2 uv)
{
    bool b1 = TRIANGLE_sign(uv, vertices[0], vertices[1]) < 0.0f;
    bool b2 = TRIANGLE_sign(uv, vertices[1], vertices[2]) < 0.0f;
    bool b3 = TRIANGLE_sign(uv, vertices[2], vertices[0]) < 0.0f;

    if((b1 == b2) && (b2 == b3)){return color;}
    return vec3(-1.0);

}
vec3 TRIANGLE(vec3 color, vec2 vertices[3], vec2 uv);
void main()
{



    vec3 eye=vec3(-0.2,0.28,0.0);

float m=length(screenpos-eye);
float dist= length(screenpos);


    if (dist < 0.7)
    {

        frag_color= vec4(0.9,0.9,0.0,1.0);

    }


    //eye
    if (m < 0.1)
    {

        frag_color = vec4(0.0,0.0,0.0,1.0);

    }


    vec2 uv = screenpos.xy;

    vec3 color;

    vec2 VERTS[3] = vec2[]
    (
    vec2(0.18, 0.0),
    vec2(1.0, -0.25),
    vec2(0.8, 0.25)
    );

    color = TRIANGLE(vec3(0.0,0.0,0.0), VERTS, uv);

    if (color!= vec3(-1.0)){
    frag_color = vec4(color,1.0);
    }
}




//    // Convert RGB to RGBA (in other words, add an alpha value).
   //frag_color = vec4(trii, 1.0);
//    // If flickering, multiply it with a sinusoidal wave that oscillates over time
//    if(flicker)
//        frag_color.rgb *= 0.5 * (1 + cos(2 * PI * time));

