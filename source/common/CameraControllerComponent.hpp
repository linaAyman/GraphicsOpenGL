//
// Created by Lina on 27-Nov-20.
//

#ifndef GFX_LAB_CAMERACONTROLLERCOMPONENT_HPP
#define GFX_LAB_CAMERACONTROLLERCOMPONENT_HPP

#include <Component.hpp>
#include <camera/controllers/fly_camera_controller.hpp>
#include <shader.hpp>
#include <application.hpp>
#include "input/keyboard.hpp"
#include <input/mouse.hpp>

class CameraControllerComponent : public Component
{public:
    our::Mouse mouse;
    our::Application * app;

    our::FlyCameraController* cameracontr;
    our::ShaderProgram* program;
    double deltaTime;

    void setApp(our::Application* app)
    {
        this->app=app;
    }

    void setTime()
    {
        this->deltaTime=app->getdeltatime();
    }

    void setCamContr(our::FlyCameraController* cameracontr)
    {
        this->cameracontr=cameracontr;
    }

    void setShader(our::ShaderProgram* program)
    {
        this->program=program;
    }

    void Update() override
    {

        cameracontr->update(deltaTime);
        //main_camera_controller.update(deltaTime);
        //weapon.rotation.z += deltaTime;

        //glm::vec4 button_tint = {0.1f, 0.1f, 0.1f, 1.0f};

       mouse=app->getMouse();
        auto mouse_position = mouse.getMousePosition();
        mouse_position.y = app->getFrameBufferSize().y - mouse_position.y;


    }

    void Destroy() override
    {
        program->destroy();
    }

};

#endif //GFX_LAB_CAMERACONTROLLERCOMPONENT_HPP
