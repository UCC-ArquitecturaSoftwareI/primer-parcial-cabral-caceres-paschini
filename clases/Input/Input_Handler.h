//
// Created by martin on 9/5/20.
//

#ifndef RAYLIBTEMPLATE_INPUT_HANDLER_H
#define RAYLIBTEMPLATE_INPUT_HANDLER_H

#include "raylib.h"
#include "../Personaje/Player.h"

class Input_Handler {
private:
    Vector2 KeyPress;
    Player *Play;
    bool CanJump;

public:

    Input_Handler(Player *Ch);

    void setKeyPress();

    int GetCharStatus();

    void GetCanJump(bool can);

};


#endif //RAYLIBTEMPLATE_INPUT_HANDLER_H
