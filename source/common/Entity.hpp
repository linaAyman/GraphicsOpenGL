//
// Created by Lina on 27-Nov-20.
//

#ifndef GFX_LAB_ENTITY_HPP
#define GFX_LAB_ENTITY_HPP

#include <Component.hpp>
#include <vector>

class Entity{
public:

    std::vector<Component*> Components;

    void addComp(Component* cmp)
    {
        Components.push_back(cmp);

    }
    void UpdateComps()
    {
        for (int i=0; i<Components.size(); i++ )
        {
            Components[i]->Update();
        }
    }

    void removeComp()
    {
       Components.pop_back();
    }

    std::vector<Component*> getComponent()
    {
        return Components;
    }

};

#endif //GFX_LAB_ENTITY_HPP
