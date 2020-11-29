//
// Created by Lina on 28-Nov-20.
//
//
// Created by Lina on 28-Nov-20.
//

#include <application.hpp>
#include <PlayState.hpp>
#include <Menu.hpp>


class StateManager: public our::Application {
public:
    PlayState playState;


    // Menu* MenuState;

    enum State {
        GAME,
        MENU,
        EXIT
    };
    our::WindowConfiguration getWindowConfiguration() override {
        return { "Phase 2", {1280, 720}, false };}

    void onInitialize() override
    {
        playState.setApp(this);
        playState.onInitialize();
        //set state-->MENU
    }

    void onDraw(double deltaTime) override
    {
        playState.onDraw(deltaTime);
    }

    void onDestroy() override
    {
        playState.onDestroy();
    }


};



int main(int argc, char** argv)
{
    return StateManager().run();
}
