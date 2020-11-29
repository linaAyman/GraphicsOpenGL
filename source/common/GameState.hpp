//
// Created by Lina on 26-Nov-20.
//
#include <states.h>
#ifndef GFX_LAB_GAMESTATE_H
#define GFX_LAB_GAMESTATE_H


class GameState {


public:


    GameState(){}
    virtual ~GameState(){}

    static State gameState;

    virtual void onInitialize(){}                  // Called once before the game loop.
    virtual void onDraw(double deltaTime){}      // Called every frame in the game loop passing the time taken to draw the frame "Delta time".
    virtual void onDestroy(){}                  // Called once after the game loop ends for house cleaning.

//    static void setState(State state) { gameState = state; }
//    static State getState() { return gameState; }

    //virtual void Update(double deltaTime) = 0;
};


#endif //GFX_LAB_GAMESTATE_H
