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

public:

    Input_Handler(Player *Ch);

    void setKeyPress();

    int GetCharStatus();

};


#endif //RAYLIBTEMPLATE_INPUT_HANDLER_H
