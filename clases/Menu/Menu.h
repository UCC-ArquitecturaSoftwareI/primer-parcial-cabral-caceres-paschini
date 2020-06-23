
//
// Created by Catalina on 27/05/2020.
//

#ifndef RAYLIBTEMPLATE_MENU_H
#define RAYLIBTEMPLATE_MENU_H

#include <raylib.h>
#include "../Music Renderer/Sound_Render.h"
#include "../State/State.h"


class Menu : public State {
private:
    Texture2D Background;
    Rectangle Back_;
    Rectangle Button;
    Rectangle Mouse;
    float scrollingBack = 0.0f;
    Sound_Render *Srend;
    int Goto;
public:
    Menu();

    void Update_Menu();

    void Draw();

    int Detect_Input();

    void On() override;

    int Off() override;

    ~Menu();

};


#endif //RAYLIBTEMPLATE_MENU_H