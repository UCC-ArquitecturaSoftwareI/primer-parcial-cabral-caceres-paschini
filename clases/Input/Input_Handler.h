//
// Created by martin on 9/5/20.
//

#ifndef RAYLIBTEMPLATE_INPUT_HANDLER_H
#define RAYLIBTEMPLATE_INPUT_HANDLER_H

#include "raylib.h"
#include "../Character/Character.h"
#include "../Music Renderer/Sound_Render.h"

class Input_Handler {
private:
    Vector2 KeyPress;
    Character *Play;
    Sound_Render *MUS;
    bool CanJump;

public:

    Input_Handler(Character *Ch, Sound_Render *MU);

    void setKeyPress();

    int GetCharStatus();

    void GetCanJump(bool can);

};


#endif //RAYLIBTEMPLATE_INPUT_HANDLER_H
