//
// Created by Lina on 27-Nov-20.
//

#ifndef GFX_LAB_MESHCOMPONENT_HPP
#define GFX_LAB_MESHCOMPONENT_HPP

#include <mesh/mesh.hpp>
#include <Component.hpp>
#include <shader.hpp>
#include <glad/gl.h>

class MeshComponent : public Component
{
public:
    our::Mesh* mesh;
    our::ShaderProgram* program;
    MeshComponent(){}
    GLsizei start = 0;
    GLsizei count = 0;

    void setMesh(our::Mesh* mesh)
    {
        this->mesh=mesh;
    }

    void setShader(our::ShaderProgram* program)
    {
        this->program=program;
    }

    void Update() override
    {
//        glUseProgram(*program);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //program->set("tint", glm::vec4(1, 1, 1, 1));
        mesh->draw(start,count);

//        glClear(GL_DEPTH_BUFFER_BIT);
    }

    void Destroy() override
    {
        mesh->destroy();
        program->destroy();
    }
};

#endif //GFX_LAB_MESHCOMPONENT_HPP
