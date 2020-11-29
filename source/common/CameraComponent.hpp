//
// Created by Lina on 27-Nov-20.
//

#ifndef GFX_LAB_CAMERACOMPONENT_HPP
#define GFX_LAB_CAMERACOMPONENT_HPP

#include <Component.hpp>
#include <camera/camera.hpp>
#include <shader.hpp>
#include <TransformComponent.hpp>


class CameraComponent: public Component
{public:
    our::Camera *camera;
    our::ShaderProgram* program;
    TransformComponent* tr;


    void setCam(our::Camera* camera)
    {
        this->camera=camera;
    }

    void setTransform(TransformComponent* tr)
    {
        this->tr=tr;
    }

    void setShader(our::ShaderProgram* program)
    {
        this->program=program;
    }


    void Update() override
    {

        program->set("transform", camera->getVPMatrix() * tr->to_mat4());
    }

    void Destroy() override
    {
        program->destroy();
    }

};

#endif //GFX_LAB_CAMERACOMPONENT_HPP
