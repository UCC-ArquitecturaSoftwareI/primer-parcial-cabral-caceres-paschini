
//
// Created by Catalina on 27/05/2020.
//

#ifndef RAYLIBTEMPLATE_MENU_H
#define RAYLIBTEMPLATE_MENU_H

#include <raylib.h>
#include "../Music Renderer/Sound_Render.h"



class Menu {
private:
    Texture2D Background;
    Rectangle Back_;
    Rectangle Button;
    Rectangle Mouse;
    float scrollingBack = 0.0f;
    Sound_Render *Srend;

public:
    Menu ();

    void Update_Menu();

    void Draw();

    bool Detect_Input();
};


#endif //RAYLIBTEMPLATE_MENU_H