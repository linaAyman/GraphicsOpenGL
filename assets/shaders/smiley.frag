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

vec3 TRIANGLE(vec3 color, vec2 vertices[3], vec2 Pos);
void main() {
    // Convert RGB to RGBA (in other words, add an alpha value).
    //    frag_color = vec4(color, 1.0);
    //    // If flickering, multiply it with a sinusoidal wave that oscillates over time
    //    if(flicker)
    //        frag_color.rgb *= 0.5 * (1 + cos(2 * PI * time));



    vec3 Eye1Center=vec3(0.25,0.25,0.0);
    vec3 Eye2Center=vec3(-0.25,0.25,0.0);
    vec3 blackMouth=vec3(0.0,-0.25,0.0);
    vec3 MouthCenter=vec3(0.0,-0.12,0.0);

    float dist = length(screenpos);
    float distEye1 = length(screenpos-Eye1Center);
    float distEye2 = length(screenpos-Eye2Center);
    float distMouth =length(screenpos-MouthCenter);
    float distBlack = length(screenpos-blackMouth);


    vec2 Pos = screenpos.xy;

    vec2 VERTS[3] = vec2[]
    (
    vec2(-0.4, -0.25),
    vec2(0.4, -0.25),
    vec2(0.0, 0.2)
    );

    vec3 color = TRIANGLE(vec3(1.0,1.0,0.0), VERTS, Pos);


    if(dist < 0.75){
        frag_color = vec4(1.0, 1.0, 0.0, 1.0); //big yellow circle
    } else {
        frag_color = vec4(0.0, 0.0, 0.0, 1.0);
    }


    if(distBlack<0.35)
    {
        frag_color= vec4(0.0, 0.0, 0.0, 1.0); //small black circle
    }

    if(distMouth<0.35)
    {
        frag_color = vec4(1.0, 1.0, 0.0, 1.0); //smaller yellow circle
    }

    if(color!= vec3(-1.0)){
        frag_color = vec4(color,1.0); //yellow triangle
    }

    if(distEye1 < 0.1){
        frag_color = vec4(0.0, 0.0, 0.0, 1.0);
    }

    if(distEye2 < 0.1){
        frag_color = vec4(0.0, 0.0, 0.0, 1.0);
    }

}

float TRIANGLE_sign(vec2 p1, vec2 p2, vec2 p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

vec3 TRIANGLE(vec3 color, vec2 vertices[3], vec2 Pos)
{
    bool b1 = TRIANGLE_sign(Pos, vertices[0], vertices[1]) < 0.0f; //3 line equations
    bool b2 = TRIANGLE_sign(Pos, vertices[1], vertices[2]) < 0.0f;
    bool b3 = TRIANGLE_sign(Pos, vertices[2], vertices[0]) < 0.0f;

    if((b1 == b2) && (b2 == b3))return color;
    return vec3(-1.0);
}