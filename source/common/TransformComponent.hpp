//
// Created by Lina on 27-Nov-20.
//

#ifndef GFX_LAB_TRANSFORMCOMPONENT_HPP
#define GFX_LAB_TRANSFORMCOMPONENT_HPP

#include <Component.hpp>
#include <shader.hpp>
#include <glm/gtx/euler_angles.hpp>



class TransformComponent : public Component{
public:

    our::ShaderProgram* program;

    glm::vec3 translation = {0,0,0};
    glm::vec3 rotation = {0,0,0};
    glm::vec3 scale = {2,2,2};


    //TransformComponent(){}

    //TransformComponent(glm::vec3 t, glm::vec3 r, glm::vec3 s) : translation(t), rotation(r), scale(s) {}

    void setTransform(glm::vec3 t,glm::vec3 r,glm::vec3 s)
    {
        this->translation=t;
        this->rotation=r;
        this->scale=s;
    }

    void setShader(our::ShaderProgram* program)
    {
        this->program=program;
    }

    glm::mat4 to_mat4() const
    {
        return glm::translate(glm::mat4(1.0f), translation) *
               glm::yawPitchRoll(rotation.y, rotation.x, rotation.z) *
               glm::scale(glm::mat4(1.0f), scale);
    }

    void Update() override
    {
        glUseProgram(*program);
        //glClear(GL_COLOR_BUFFER_BIT);

        //program->set("tint", glm::vec4(1, 1, 1, 1));
        program->set("transform", to_mat4());
    }

    void Destroy() override
    {
        program->destroy();
    }

};

#endif //GFX_LAB_TRANSFORMCOMPONENT_HPP
