//
// Created by passant on 11/28/2020.
//
//
// Created by passant on 11/28/2020.
//
#include <GameState.hpp>
#include <shader.hpp>
#include <glm/vec2.hpp>
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include "input/keyboard.hpp"
#include "input/mouse.hpp"
#include <World.hpp>
#include <MeshComponent.hpp>
#include <CameraComponent.hpp>
#include <CameraControllerComponent.hpp>
#include <TransformComponent.hpp>
#include <Entity.hpp>
#include <mesh/mesh.hpp>
#include <application.hpp>
#include <mesh/mesh-utils.hpp>
class PlayState: public GameState {
public:
   // StateManager * stateManager;
    our::Application * app;
    our::Mesh* mesh_cuboid= new our::Mesh();
    our::ShaderProgram* program= new our::ShaderProgram();
    our::FlyCameraController* flycameracontroller = new our::FlyCameraController();
    our::Camera * camera= new our::Camera();
    //our::FlyCameraController* flycameracontroller2 = new our::FlyCameraController();
    //our::Camera * camera2= new our::Camera();
    World my_world;
    Entity* Entity1= new Entity();
    Entity* Entity2= new Entity();

        void onInitialize() override {
        ////////////////////////////////////////////////////////////////////////
        //Components//
        ///////////////////////////////////////////////////////////////////////
        MeshComponent* meshcomp=new MeshComponent();
        MeshComponent* meshcomp2=new MeshComponent();

        CameraComponent* cameracomp=new CameraComponent();
        CameraControllerComponent* cameracontroller=new CameraControllerComponent();

        CameraComponent* cameracomp2=new CameraComponent();
        CameraControllerComponent* cameracontroller2=new CameraControllerComponent();

        TransformComponent* transformcomp=new TransformComponent();
        TransformComponent* transformcomp2=new TransformComponent();
        ////////////////////////////////////////////////////////////////////////
        //Initializing Entity adding components//
        /////////////////////////////////////////////////////////////////////////
        Entity1->addComp(transformcomp);
        Entity1->addComp(cameracontroller);
        Entity1->addComp(cameracomp);
        Entity1->addComp(meshcomp);

        Entity2->addComp(transformcomp2);
        //Entity2->addComp(cameracontroller2);
        Entity2->addComp(cameracomp2);
        Entity2->addComp(meshcomp2);
        ////////////////////////////////////////////////////////////////////////
//not sure//Cuboid Mesh

        our::mesh_utils::Cuboid(*mesh_cuboid,true);
        meshcomp->setMesh(mesh_cuboid);
        meshcomp2->setMesh(mesh_cuboid);

//TODO: attach shaders//
        program->create();
        program->attach("../assets/shaders/transform.vert", GL_VERTEX_SHADER);
        program->attach("../assets/shaders/tint.frag", GL_FRAGMENT_SHADER);
        program->link();

        ///////////////////////////////////////////////////////////////////////
        //Setting Shader//
        ///////////////////////////////////////////////////////////////////////

        transformcomp->setShader(program);
        meshcomp->setShader(program);
        cameracomp->setShader(program);
        cameracontroller->setShader(program);

        transformcomp2->setShader(program);
        meshcomp2->setShader(program);
        cameracomp2->setShader(program);
//        cameracontroller2->setShader(program);
        ///////////////////////////////////////////////////////////////////////
        transformcomp->setTransform( {0,-1,0}, {0,0,0}, {7,2,7} );
        transformcomp2->setTransform({0,1,0},{0,0,0}, {2,2,2} );

        ///////////////////////////////////////////////////////////////////////
        //Setting Camera-CameraController//
        ///////////////////////////////////////////////////////////////////////
        int width, height;
        glfwGetFramebufferSize(app->getWindow(), &width, &height);
        cameracomp->setTransform(transformcomp);
        cameracomp2->setTransform(transformcomp2);
        camera->setEyePosition({10, 10, 10});
        camera->setTarget({0, 0, 0});
        camera->setUp({0, 1, 0});
        camera->setupPerspective(glm::pi<float>()/2, static_cast<float>(width)/height, 0.1f, 100.0f);

//        camera2->setEyePosition({10, 10, 10});
//        camera2->setTarget({0, 0, 0});
//        camera2->setUp({0, 1, 0});
//        camera2->setupPerspective(glm::pi<float>()/2, static_cast<float>(width)/height, 0.1f, 100.0f);
        cameracontroller->setApp(app);
        cameracomp->setCam(camera);
        flycameracontroller->initialize(app , camera);
        cameracontroller->setTime();
        cameracontroller->setCamContr(flycameracontroller);

//        cameracontroller2->setApp(app);
        cameracomp2->setCam(camera);
//        flycameracontroller2->initialize(app , camera2);
//        cameracontroller2->setTime();
//        cameracontroller2->setCamContr(flycameracontroller);
        ///////////////////////////////////////////////////////////////////////
        my_world.addEntity(Entity1);
        my_world.addEntity(Entity2);



    }
    void setApp(our::Application* app)
    {
        this->app=app;
    }
    void onDraw(double deltaTime) override {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        my_world.System();
    }
    void onDestroy() override{

        for (int i=0; i< ((my_world.Entities).size());i++) {

            for(int j=0;j<(my_world.Entities[i]->Components).size();j++)
            {
                my_world.Entities[i]->Components[j]->Destroy();
            }
            my_world.removeEntity();
        }
    }

};
