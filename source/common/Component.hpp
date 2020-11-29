//
// Created by Lina on 27-Nov-20.
//

#ifndef GFX_LAB_COMPONENT_HPP
#define GFX_LAB_COMPONENT_HPP


class Component {
public:

   // virtual ~Component(){}
    //gets type of component to use it in world entity
    // int gettype();
     Component(){}
    virtual void  Update(){}
    virtual void Destroy(){}

};

#endif //GFX_LAB_COMPONENT_HPP
