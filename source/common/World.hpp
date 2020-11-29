//
// Created by Lina on 27-Nov-20.
//

#ifndef GFX_LAB_WORLD_HPP
#define GFX_LAB_WORLD_HPP

#include <Entity.hpp>
#include <vector>

class World
{
public:
    std::vector<Entity*> Entities;

    void addEntity(Entity* ent)
    {
        Entities.push_back(ent);
    }

    void removeEntity()
    {
        Entities.pop_back();
    }

    void System()
    {
        for (int i=0; i< Entities.size();i++)
        {
            Entities[i]->UpdateComps();
        }
    }


};

#endif //GFX_LAB_WORLD_HPP
